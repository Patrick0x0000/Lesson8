/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/

	//int red = 255;
	//int green = 255;
	//int blue = 255;

	void DrawCircles(int coord_x, int coord_y, int r, int g, int b);
	void DrawTarget(int coord_x, int coord_y);
	int MoveTarget_dx();
	int MoveTarget_dy();
	void Overlapping1(int dwx, int dwx2, int dwy, int dwy2);
	void Overlapping2(int dwx, int dwx2, int dwy, int dwy2);
	void Overlapping3(int dwx, int dwx2, int dwy, int dwy2);
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	bool Inhibit_Button_up = false;
	bool Inhibit_Button_left = false;
	bool Inhibit_Button_down = false;
	bool Inhibit_Button_right = false;

	int targetCoord_x = 400;
	int targetCoord_y = 300;
	int dx = 0;
	int dy = 0;

	int red = 255;
	int green = 255;
	int blue = 255;

	int circle1_x =  700 ;
	int circle1_y =  45;
	int circle2_x =  500;
	int circle2_y = 505;
	int circle3_x = 305;
	int circle3_y = 205;

	int clampScreen_x(int x);
	int clampScreen_y(int y);

	bool Ball1Eaten = false;
	bool Ball2Eaten = false;
	bool Ball3Eaten = false;

};