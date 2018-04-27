/*!\file MouseTool.cpp
*
* This will house all of the function declarations for the class MouseTool.
*
*/

#include "MouseTool.h"

//-------------------------------------------------------------

/*! Constructor
\
*/
MouseTool::MouseTool()
{
	m_MouseMarker.setSize(sf::Vector2f(0.1f, 0.1f));

	m_MouseMarker.setFillColor(sf::Color::Yellow);
}

//-------------------------------------------------------------

/*! Deconstructor
\
*/
MouseTool::~MouseTool()
{
}

//-------------------------------------------------------------

/*! Get Mouse Pos : This will be used to get the position of mouse. 
\Param One - RenderWindow : This will be used to constrain the mouse position to the window/view. 
*/
sf::Vector2f MouseTool::m_GetMousePos(sf::RenderWindow &window)
{

	// Get the mouse position. 
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);

	// Convert it to pixel coords. 
	m_MousePos = window.mapPixelToCoords(pixelPos); 

	return m_MousePos;
}

//-------------------------------------------------------------

/*! Update Mouse : This will be used to update the position of the mouse marker. 
\
*/
void MouseTool::m_UpdateMouse()
{
	m_MouseMarker.setPosition(m_MousePos.x, m_MousePos.y);
}

//-------------------------------------------------------------

/*! Draw Mouse Marker : This will be used to draw the marker on the screen. 
\Param One - RenderWindow : This will be the window the item is drawn onto. 
*/
void MouseTool::m_DrawMouseMarker(sf::RenderWindow &window)
{
	window.draw(m_MouseMarker);

	if (m_Line.getVertexCount() != NULL)
	{
		window.draw(m_Line);
	}
}

//-------------------------------------------------------------

/*! Cut : This will be used to define where the player wants to cut. 
\Param One - RenderWindow : Used to check for a mouse Click/Release.
*/
void MouseTool::m_Cut(sf::RenderWindow &window)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				// std::cout << "LMB Pressed" << std::endl;

				m_CutStart = sf::Vector2f(m_MousePos); 
			}
		}

		else if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				// std::cout << "LMB Released" << std::endl;

				m_CutEnd = sf::Vector2f(m_MousePos);

				m_CreateLine(); 
			}
		}
	}

}

//-------------------------------------------------------------

/*! Create Line : This will be used to draw a line between the two defined points, where the mouse was clicked and released. 
\
*/
void MouseTool::m_CreateLine()
{
	// Reset the line.
	m_Line.clear();
	m_Line.setPrimitiveType(sf::Lines); 
	m_Line.resize(2); 

	// Define first point.
	m_Line[0].position = m_CutStart;
	m_Line[0].color = sf::Color::Yellow;

	// Define end point. 
	m_Line[1].position = m_CutEnd;
	m_Line[0].color = sf::Color::Yellow;
}

//-------------------------------------------------------------

/*! Line Intersect : This will be used to detect whether two lines defined by four points intersect.
\Param One - Vector2f : The coords for the first lines first point.
\Param Two - Vector2f : The coords for the first lines second point.
\Param One - Vector2f : The coords for the second lines first point.
\Param One - Vector2f : The coords for the second lines second point.
*/
bool MouseTool::m_LineIntersect(sf::Vector2f p2, sf::Vector2f p3)
{
	if (m_Line.getVertexCount() > 0)
	{
		// Calculate all of the values 
		float l_A1 = m_CutEnd.y - m_CutStart.y;
		float l_B1 = m_CutStart.x - m_CutEnd.x;
		float l_C1 = l_A1 * m_CutStart.x + l_B1 * m_CutStart.y;
		float l_A2 = p3.y - p2.y;
		float l_B2 = p2.x - p3.x;
		float l_C2 = l_A2 * p2.x + l_B2 * p2.y;
		float l_fDenominator = l_A1 * l_B2 - l_A2 * l_B1;

		sf::Vector2f l_IntersectionPoint;

		// Find the intersection point. 

		if (l_fDenominator == 0)
		{
			std::cout << "Segment Intersect : False" << std::endl;

			return false;
		}

		l_IntersectionPoint.x = (l_B2 * l_C1 - l_B1 * l_C2) / l_fDenominator;
		l_IntersectionPoint.y = (l_A1 * l_C2 - l_A2 * l_C1) / l_fDenominator;

		// Constrain check to line segments. 

		float l_rx0 = (l_IntersectionPoint.x - m_CutStart.x) / (m_CutEnd.x - m_CutStart.x);
		float l_ry0 = (l_IntersectionPoint.y - m_CutStart.y) / (m_CutEnd.y - m_CutStart.y);
		float l_rx1 = (l_IntersectionPoint.x - p2.x) / (p3.x - p2.x);
		float l_ry1 = (l_IntersectionPoint.y - p2.y) / (p3.y - p2.y);

		if (((l_rx0 >= 0 && l_rx0 <= 1) || (l_ry0 >= 0 && l_ry0 <= 1)) &&
			((l_rx1 >= 0 && l_rx1 <= 1) || (l_ry1 >= 0 && l_ry1 <= 1)))
		{

			std::cout << "Segment Intersect : True" << std::endl;

			return true;
		}

		else
		{
			std::cout << "Segment Intersect : False" << std::endl;

			return false;
		}
	}

	return false; 
}


