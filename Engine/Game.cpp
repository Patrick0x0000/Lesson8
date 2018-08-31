/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

	dx += MoveTarget_dx();
	dy += MoveTarget_dy();
	targetCoord_x += dx;
	targetCoord_y += dy;
	
	targetCoord_x = clampScreen_x(targetCoord_x);
	targetCoord_y = clampScreen_y(targetCoord_y);

    Overlapping1(targetCoord_x, circle1_x,targetCoord_y, circle1_y);
	//Overlapping2(targetCoord_x, circle2_x, targetCoord_y, circle2_y);
	//Overlapping3(targetCoord_x, circle3_x, targetCoord_y, circle3_y);
	
}

void Game::ComposeFrame()
{
	DrawTarget(targetCoord_x, targetCoord_y);
	if(!Ball1Eaten)
		DrawCircles(circle1_x, circle1_y, red , green, blue);
	if(!Ball2Eaten)
		DrawCircles(circle2_x, circle2_y, red, green, blue);
	if(!Ball3Eaten)
		DrawCircles(circle3_x, circle3_y, red, green, blue);
}

void Game::DrawCircles(int coord_x, int coord_y, int r, int g, int b)
{
	gfx.PutPixel(coord_x - 5, coord_y + 2, r, g, b);
	gfx.PutPixel(coord_x - 5, coord_y + 1, r, g, b);
	gfx.PutPixel(coord_x - 5, coord_y, r, g, b);
	gfx.PutPixel(coord_x - 5, coord_y - 1, r, g, b);
	gfx.PutPixel(coord_x - 5, coord_y - 2, r, g, b);

	gfx.PutPixel(coord_x - 5, coord_y - 3, r, g, b);
	gfx.PutPixel(coord_x - 4, coord_y - 3, r, g, b);
	gfx.PutPixel(coord_x - 4, coord_y - 4, r, g, b);
	gfx.PutPixel(coord_x - 3, coord_y - 4, r, g, b);
	gfx.PutPixel(coord_x - 3, coord_y - 5, r, g, b);
	gfx.PutPixel(coord_x - 2, coord_y - 5, r, g, b);

	gfx.PutPixel(coord_x + 5, coord_y + 2, r, g, b);
	gfx.PutPixel(coord_x + 5, coord_y + 1, r, g, b);
	gfx.PutPixel(coord_x + 5, coord_y, r, g, b);
	gfx.PutPixel(coord_x + 5, coord_y - 1, r, g, b);
	gfx.PutPixel(coord_x + 5, coord_y - 2, r, g, b);

	gfx.PutPixel(coord_x + 5, coord_y - 3, r, g, b);
	gfx.PutPixel(coord_x + 4, coord_y - 3, r, g, b);
	gfx.PutPixel(coord_x + 4, coord_y - 4, r, g, b);
	gfx.PutPixel(coord_x + 3, coord_y - 4, r, g, b);
	gfx.PutPixel(coord_x + 3, coord_y - 5, r, g, b);
	gfx.PutPixel(coord_x + 2, coord_y - 5, r, g, b);

	gfx.PutPixel(coord_x - 2, coord_y + 5, r, g, b);
	gfx.PutPixel(coord_x - 1, coord_y + 5, r, g, b);
	gfx.PutPixel(coord_x, coord_y + 5, r, g, b);
	gfx.PutPixel(coord_x + 1, coord_y + 5, r, g, b);
	gfx.PutPixel(coord_x + 2, coord_y + 5, r, g, b);

	gfx.PutPixel(coord_x - 5, coord_y + 3, r, g, b);
	gfx.PutPixel(coord_x - 4, coord_y + 3, r, g, b);
	gfx.PutPixel(coord_x - 4, coord_y + 4, r, g, b);
	gfx.PutPixel(coord_x - 3, coord_y + 4, r, g, b);
	gfx.PutPixel(coord_x - 3, coord_y + 5, r, g, b);
	gfx.PutPixel(coord_x - 2, coord_y + 5, r, g, b);

	gfx.PutPixel(coord_x - 2, coord_y - 5, r, g, b);
	gfx.PutPixel(coord_x - 1, coord_y - 5, r, g, b);
	gfx.PutPixel(coord_x, coord_y - 5, r, g, b);
	gfx.PutPixel(coord_x + 1, coord_y - 5, r, g, b);
	gfx.PutPixel(coord_x + 2, coord_y - 5, r, g, b);

	gfx.PutPixel(coord_x + 5, coord_y + 3, r, g, b);
	gfx.PutPixel(coord_x + 4, coord_y + 3, r, g, b);
	gfx.PutPixel(coord_x + 4, coord_y + 4, r, g, b);
	gfx.PutPixel(coord_x + 3, coord_y + 4, r, g, b);
	gfx.PutPixel(coord_x + 3, coord_y + 5, r, g, b);
	gfx.PutPixel(coord_x + 2, coord_y + 5, r, g, b);
}

void Game::DrawTarget(int coord_x, int coord_y)
{
	gfx.PutPixel(coord_x - 3, coord_y - 5, 255,255,255);
	gfx.PutPixel(coord_x - 4, coord_y - 5, 255,255,255);
	gfx.PutPixel(coord_x - 5, coord_y - 5, 255,255,255);

	gfx.PutPixel(coord_x - 5, coord_y - 4, 255,255,255);
	gfx.PutPixel(coord_x - 5, coord_y - 3, 255,255,255);
	gfx.PutPixel(coord_x - 5, coord_y - 2, 255,255,255);

	gfx.PutPixel(coord_x, coord_y, 255,255,255);

	gfx.PutPixel(coord_x + 3, coord_y - 5, 255,255,255);
	gfx.PutPixel(coord_x + 4, coord_y - 5, 255,255,255);
	gfx.PutPixel(coord_x + 5, coord_y - 5, 255,255,255);

	gfx.PutPixel(coord_x + 5, coord_y - 2, 255,255,255);
	gfx.PutPixel(coord_x + 5, coord_y - 3, 255,255,255);
	gfx.PutPixel(coord_x + 5, coord_y - 4, 255,255,255);
	//--		 			   	   
	gfx.PutPixel(coord_x - 3, coord_y + 5, 255,255,255);
	gfx.PutPixel(coord_x - 4, coord_y + 5, 255,255,255);
	gfx.PutPixel(coord_x - 5, coord_y + 5, 255,255,255);

	gfx.PutPixel(coord_x - 5, coord_y + 4, 255,255,255);
	gfx.PutPixel(coord_x - 5, coord_y + 3, 255,255,255);
	gfx.PutPixel(coord_x - 5, coord_y + 2, 255,255,255);

	gfx.PutPixel(coord_x + 3, coord_y + 5, 255,255,255);
	gfx.PutPixel(coord_x + 4, coord_y + 5, 255,255,255);
	gfx.PutPixel(coord_x + 5, coord_y + 5, 255,255,255);

	gfx.PutPixel(coord_x + 5, coord_y + 2, 255,255,255);
	gfx.PutPixel(coord_x + 5, coord_y + 3, 255,255,255);
	gfx.PutPixel(coord_x + 5, coord_y + 4, 255,255,255);
}

int Game::MoveTarget_dx()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{ 
		if (Inhibit_Button_left)
		{
		}
		else
		{
			Inhibit_Button_left = true;
			return -1;
		}
	}
	else
		Inhibit_Button_left = false;

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (Inhibit_Button_right)
		{
		}
		else
		{
			Inhibit_Button_right = true;
			return 1;
		}
	}
	else
		Inhibit_Button_right = false;
}	

int Game::MoveTarget_dy()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (Inhibit_Button_up)
		{  }
		else
		{
			Inhibit_Button_up = true;
			return -1;
		}
	}
	else
		Inhibit_Button_up = false;


	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (Inhibit_Button_down)
		{	}
		else
		{
			Inhibit_Button_down = true;
			return 1;
		}
	}
	else
		Inhibit_Button_down = false;

	return 0;
}



void Game::Overlapping1(int dwx, int dwx2, int dwy, int dwy2)
{
	if (dwx + 5 >= dwx2 - 5 || dwx - 5 <= dwx2 + 5 || dwy + 5 >= dwy2 - 5 || dwy - 5 <= dwy2 + 5)
	{
		red =0;
	}	
}

void Game::Overlapping2(int dwx, int dwx2, int dwy, int dwy2)
{
	if (dwx + 5 >= dwx2 - 5 && dwx - 5 <= dwx2 + 5 && dwy + 5 >= dwy2 - 5 && dwy - 5 <= dwy2 + 5)
	{
		//Ball2Eaten = true;
	}
}
void Game::Overlapping3(int dwx, int dwx2, int dwy, int dwy2)
{
	if (dwx + 5 >= dwx2 - 5 && dwx - 5 <= dwx2 + 5 && dwy + 5 >= dwy2 - 5 && dwy - 5 <= dwy2 + 5)
	{
		Ball3Eaten = true;
	}
}
int Game::clampScreen_x(int x)
{
	if (x + 5 > gfx.ScreenWidth - 1)
	{
		dx = 0;
		return gfx.ScreenWidth - 6;
	}
	else if (x - 5 < 0)
	{
		dx = 0;
		return 5;
	}
	else
	{
		return x;
	}
}

int Game::clampScreen_y(int y)
{
	if (y + 5 > gfx.ScreenHeight - 1)
	{
		dy = 0;
		return gfx.ScreenHeight - 6;
	}
	else if (y - 5 < 0)
	{
		dy = 0;
		return 5;
	}
	else
		return y;
}
