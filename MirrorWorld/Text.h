/*
	a HubObject class that handles text images by converting Strings.
*/

#pragma once

#include "HudObject.h"

namespace sf
{
namespace hud
{

static const float BASE_TEXT_SIZE = 32.0f;


class Text : public HudObject
{
public:
	
	//Constructor / Destructor
	Text()
	{
		setFontSize(32);
		setAngle(0);
	}
	~Text(){}

	//operators
	Text& Text::operator= (const Text& me)
	{
		// check for self-assignment by comparing the address of the
		// implicit object and the parameter
		if (this == &me)
			return *this;
 
		// do the copy
		myText = me.myText;
		myFontSize = me.myFontSize;
		myColor = me.myColor;
		myLetterSprites = me.myLetterSprites;
		myPosition = me.myPosition;
 
		// return the existing object
		return *this;
	}

	Text& Text::operator= (const std::string text)
	{
		// do the copy
		Text::operator=(*this);
		this->setText(text);
 
		// return the existing object
		return *this;
	}

public:

	//HubObject Functions:
	virtual void move(float x, float y)
	{
		setPosition(myPosition.x + x, myPosition.y + y);
	}

	virtual void setPosition(float x, float y)
	{
		myPosition.x = x;
		myPosition.y = y;

		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				myLetterSprites[line][letter].setPosition(x, y);
			}
		}

		alignText();
	}

	virtual void setColor(sf::Color color)
	{
		myColor = color;

		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				myLetterSprites[line][letter].setColor(myColor);
			}
		}
	}

	virtual void rotate(double degrees)
	{
		myAngle += degrees;

		//ensure that our angle stays within a circle
		adjustAngle();

		//actually rotates letters
		applyAngle();

		//Since the text is being modified, we have to align it again.
		alignText();
	}

	virtual void setAngle(double degrees)
	{
		myAngle = degrees;

		//ensure that our angle stays within a circle
		adjustAngle();

		//actually rotates letters
		applyAngle();

		//Since the text is being modified, we have to align it again.
		alignText();
	}

public:

	//function that sets the text, create the sprites, then aligns them.
	void setText(std::string text)
	{
		myText = text;

		myLetterSprites.clear();

		//If we actually have text to work with...
		if(text.size() > 0)
		{
			myLetterSprites.push_back(std::vector<sf::Sprite>());

			int line = 0;
			int letter = 0;

			int const LETTERS_PER_LINE = 10;
			int const LENGTH_WIDTH_PER_LETTER = 32;

			for(int i = 0; i < text.size(); i++)
			{
				if(text[i] == '\n')
				{
					//Go down a line
					myLetterSprites.push_back(std::vector<sf::Sprite>());

					//we added a line and a line starts at 0
					line++;
					letter = 0;
				}
				else
				{
					//Add LetterSprite to the line
					myLetterSprites[myLetterSprites.size()-1].push_back(sf::Sprite());

					myLetterSprites[line][letter].setTexture(mw::Texture::hud::TEXTURE_TEXT);
					myLetterSprites[line][letter].setTextureRect(sf::IntRect((mw::convertCharToLetterValue(text[i]) % LETTERS_PER_LINE) * LENGTH_WIDTH_PER_LETTER,
																			(int)(mw::convertCharToLetterValue(text[i]) / LETTERS_PER_LINE) * LENGTH_WIDTH_PER_LETTER,
																			LENGTH_WIDTH_PER_LETTER, LENGTH_WIDTH_PER_LETTER));

					//we just added a letter so move the index
					letter++;
				}
			}

			setColor(myColor);
			setFontSize(myFontSize);

			alignText();
		}
	}

	void setFontSize(int fontSize)
	{
		myFontSize = fontSize;

		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				myLetterSprites[line][letter].scale(myFontSize / BASE_TEXT_SIZE, myFontSize / BASE_TEXT_SIZE);
			}
		}
	}


private:

	//functions that are used within public functions.

	//Aligns the text with itself and aligns it with the angle
	void alignText() 
	{
		if(myText.size() > 0)
		{
			for(int line = 0; line < myLetterSprites.size(); line++)
			{
				for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
				{
					if(letter > 0)
					{
						myLetterSprites[line][letter-1].setPosition(myFontSize * cos(myAngle), myFontSize * -sin(myAngle));
					}
					else if(line > 0 && letter == 0)
					{
						myLetterSprites[line-1][letter].setPosition(myFontSize * (letter * cos((myAngle-90))), myFontSize * (line * -sin((myAngle-90))));
					}
				}
			}
		}
	}

	void adjustAngle()
	{
		//ensure that our angle stays within a circle
		while(myAngle >= 360)
		{
			myAngle -= 360;
		}

		while(myAngle < 0)
		{
			myAngle += 360;
		}
	}

	void applyAngle()
	{
		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				myLetterSprites[line][letter].setRotation(myAngle);
			}
		}
	}

private:
	std::vector<std::vector<sf::Sprite>> myLetterSprites;

	std::string myText;

	int myFontSize;

private:
	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for(int i = 0; i < myLetterSprites.size(); i++)
		{
			for(int j = 0; j < myLetterSprites[i].size(); j++)
			{
				target.draw(myLetterSprites[i][j], states);
			}
		}
	}

};


}//end of namespace hud
}//end of namespace sf