//    This file is part of LightBot.
//
//    LightBot is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    LightBot is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with LightBot.  If not, see <http://www.gnu.org/licenses/>.
//    Authors : Lilian Gallon, Tristan Renaudon

#include "Utils.h"

// Because we declared thos variables as static const, we have to initalize those there
const std::string Utils::FONT_PATH = "resources/fonts/";
const std::string Utils::IMG_PATH = "resources/images/";
const std::string Utils::LEVELS_PATH = "resources/levels/";


// Returns the absolute value of
float Utils::abs(const float &value){
    if(value>0)
        return value;
    return -value;
}

// Gives the current time (hh:mm:ss) in a string
std::string Utils::getTime(){
    time_t t = time(0); // Time from now (0)
    struct tm* now = localtime(&t);

    std::string hour,min,sec;

    // reformat -> get 10:02:05 instead of 10:2:5 for exemple
    if(now->tm_hour>=10){
        hour = std::to_string(now->tm_hour);
    }else{
          hour = "0" + std::to_string(now->tm_hour);
    }

    if(now->tm_min>=10){
        min = std::to_string(now->tm_min);
    }else{
        min = "0" + std::to_string(now->tm_min);
    }

    if(now->tm_sec>=10){
        sec = std::to_string(now->tm_sec);
    }else{
        sec = "0" + std::to_string(now->tm_sec);
    }
    //delete now; don't delete now otherwise it crashes (wtf)
    return "[" + hour + ":" + min + ":" + sec + "] ";
}

// Split a string into others with a specified delimliter
std::vector<std::string> Utils::split(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if(pos == std::string::npos)
            pos = str.length();

        std::string token = str.substr(prev, pos-prev);
        if(!token.empty())
            tokens.push_back(token);

        prev = pos + delim.length();
    }
    while(pos < str.length() && prev < str.length());
    return tokens;
}

// Turn the robot clockwise according to its orientation
Utils::Orientation Utils::turn_clockwise(Utils::Orientation actual_orientation)
{
    Orientation final_orientation = Orientation::NONE;
    switch (actual_orientation) {
    case Orientation::DOWN:
        final_orientation=Orientation::DOWN_LEFT;
        break;
    case Orientation::DOWN_LEFT:
        final_orientation=Orientation::UP_LEFT;
        break;
    case Orientation::DOWN_RIGHT:
        final_orientation=Orientation::DOWN;
        break;
    case Orientation::UP:
        final_orientation=Orientation::UP_RIGHT;
        break;
    case Orientation::UP_LEFT:
        final_orientation=Orientation::UP;
        break;
    case Orientation::UP_RIGHT:
        final_orientation=Orientation::DOWN_RIGHT;
        break;
    default:
        break;
    }
    return final_orientation;
}


// Turn the robot counterclock according to its orientation
Utils::Orientation Utils::turn_counterclock(Utils::Orientation actual_orientation)
{
    Orientation final_orientation = Orientation::NONE;
    switch (actual_orientation) {
    case Orientation::DOWN:
        final_orientation=Orientation::DOWN_RIGHT;
        break;
    case Orientation::DOWN_LEFT:
        final_orientation=Orientation::DOWN;
        break;
    case Orientation::DOWN_RIGHT:
        final_orientation=Orientation::UP_RIGHT;
        break;
    case Orientation::UP:
        final_orientation=Orientation::UP_LEFT;
        break;
    case Orientation::UP_LEFT:
        final_orientation=Orientation::DOWN_LEFT;
        break;
    case Orientation::UP_RIGHT:
        final_orientation=Orientation::UP;
        break;
    default:
        break;
    }
    return final_orientation;
}

// Gives the position of the robot in pixel with its index
sf::Vector2f Utils::positionToPixel(const sf::Vector2f &pos_in_index, const sf::Vector2f &gap, const int &radius)
{
    sf::Vector2f pos = gap;

    if((int)pos_in_index.x%2!=0 && (int)pos_in_index.y%2==0){
        if(pos_in_index.y==0){
            pos.y -= (radius*sin(Utils::PI/3.)+1);
        }else{
            pos.y += pos_in_index.y * (radius*sin(Utils::PI/3.)+1) + (radius*sin(Utils::PI/3.)+1);
        }
    }else if((int)pos_in_index.x%2==0 && (int)pos_in_index.y%2==0){
        if(pos_in_index.y==0){
            pos.y -= pos_in_index.y * 2*(radius*sin(Utils::PI/3.)+1);
        }else{
            pos.y += pos_in_index.y * 2*(radius*sin(Utils::PI/3.)+1);
        }
    }else if((int)pos_in_index.x%2!=0 && (int)pos_in_index.y%2!=0){
        if(pos_in_index.y==1){
            pos.y += pos_in_index.y * (radius*sin(Utils::PI/3.)+1);
        }else{
            pos.y += pos_in_index.y * (radius*sin(Utils::PI/3.)+1) + 2*(radius*sin(Utils::PI/3.)+1);
        }
    }else if((int)pos_in_index.x%2==0 && (int)pos_in_index.y%2!=0){
        pos.y += pos_in_index.y * 2*(radius*sin(Utils::PI/3.)+1);
    }
    pos.x += pos_in_index.x * (radius+1 + radius * cos(Utils::PI/3.)+1);

    return pos;
}
