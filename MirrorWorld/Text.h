/*
	Contains class Char and class Text

	Class Char:
		contains custom letter values and information to check 
		if its upper/lower etc.

	Class Text:
		contains custom text loaded from a custom texture
		and handles its positions, sizes, etc.


	IMPORTANT NOTE:
		
		- Text class will not work properly without the following:
			- An SFML Screen to draw to
			- An sf::Texture that contain the letters in the proper locations
*/

#pragma once

#include "MW.h"

namespace mw
{

class Char
{
public:
	Char() 
	{
		myChar = ' ';
		myIsUpper = false;
	}
	~Char() {}

	// Enum for letter values
	enum class LetterValue { INVALID = -1, A = 0, B, C, D, E, F, G, H, I, J, K, L,
						     M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, ONE, TWO, 
							 THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO, 
							 DOUBLE_QUOTE, SINGLE_QUOTE, COMMA, PERIOD, QUESTION, EXCLAMATION };
	
	/*
		Edit operators to:
			- allow ability to make Char = ' ' and make Char = Char
			- allow ability to compare Chars
			- etc
	*/

	Char& Char::operator= (const Char& me)
	{
		// check for self-assignment by comparing the address of the
		// implicit object and the parameter
		if (this == &me)
			return *this;
 
		// do the copy
		myChar = me.myChar;
		myIsUpper = me.myIsUpper;
		myLetterValue = me.myLetterValue;
 
		// return the existing object
		return *this;
	}

	//Allows mw::Char = ' ';
	//presummed working, not tested
	Char& Char::operator= (const char& letter)
	{
		Char::operator=(*this);
		this->myChar = letter;
		myLetterValue = convertCharToLetterValue(letter);

		return *this;
	}

	//Comparison operators

	inline bool operator==(const Char& comparison){ return this->myChar == comparison.myChar; }
	//inline bool operator!=(const Char& lhs, const Char& rhs){return !operator==(lhs,rhs);}
	//inline bool operator< (const Char& lhs, const Char& rhs){ /* do actual comparison */ }
	//inline bool operator> (const Char& lhs, const Char& rhs){return  operator< (rhs,lhs);}
	//inline bool operator<=(const Char& lhs, const Char& rhs){return !operator> (lhs,rhs);}
	//inline bool operator>=(const Char& lhs, const Char& rhs){return !operator< (lhs,rhs);}


public:
	/*
		(public is there to help seperate methods)

		Section where accessor / mutator methods are at
	*/

	//Accessor methods

	bool const isUpper()				{ return myIsUpper; }
	char const getChar()				{ return myChar; }
	LetterValue const getLetterValue()	{ return this->myLetterValue; }

	//mutator methods

	void isUpper(bool boolean)		{ myIsUpper = boolean; }
	void setChar(char character)	{ myChar = character; myLetterValue = convertCharToLetterValue(character);}

private:
	//Private method designed to keep translations clean
	LetterValue convertCharToLetterValue(char letter)
	{
		LetterValue conversion;

		if(letter == 'a' || letter == 'A')
		{
			conversion = LetterValue::A;
		}
		else if (letter == 'b' || letter == 'B')
		{
			conversion = LetterValue::B;
		}
		else if (letter == 'c' || letter == 'C')
		{
			conversion = LetterValue::C;
		}
		else if (letter == 'd' || letter == 'D')
		{
			conversion = LetterValue::D;
		}
		else if (letter == 'e' || letter == 'E')
		{
			conversion = LetterValue::E;
		}
		else if (letter == 'f' || letter == 'F')
		{
			conversion = LetterValue::F;
		}
		else if (letter == 'g' || letter == 'G')
		{
			conversion = LetterValue::G;
		}
		else if (letter == 'h' || letter == 'H')
		{
			conversion = LetterValue::H;
		}
		else if (letter == 'i' || letter == 'I')
		{
			conversion = LetterValue::I;
		}
		else if (letter == 'j' || letter == 'J')
		{
			conversion = LetterValue::J;
		}
		else if (letter == 'k' || letter == 'K')
		{
			conversion = LetterValue::K;
		}
		else if (letter == 'l' || letter == 'L')
		{
			conversion = LetterValue::L;
		}
		else if (letter == 'm' || letter == 'M')
		{
			conversion = LetterValue::M;
		}
		else if (letter == 'n' || letter == 'N')
		{
			conversion = LetterValue::N;
		}
		else if (letter == 'o' || letter == 'O')
		{
			conversion = LetterValue::O;
		}
		else if (letter == 'p' || letter == 'P')
		{
			conversion = LetterValue::P;
		}
		else if (letter == 'q' || letter == 'Q')
		{
			conversion = LetterValue::Q;
		}
		else if (letter == 'r' || letter == 'R')
		{
			conversion = LetterValue::R;
		}
		else if (letter == 's' || letter == 'S')
		{
			conversion = LetterValue::S;
		}
		else if (letter == 't' || letter == 'T')
		{
			conversion = LetterValue::T;
		}
		else if (letter == 'u' || letter == 'U')
		{
			conversion = LetterValue::U;
		}
		else if (letter == 'v' || letter == 'V')
		{
			conversion = LetterValue::V;
		}
		else if (letter == 'w' || letter == 'W')
		{
			conversion = LetterValue::W;
		}
		else if (letter == 'x' || letter == 'X')
		{
			conversion = LetterValue::X;
		}
		else if (letter == 'y' || letter == 'Y')
		{
			conversion = LetterValue::Y;
		}
		else if (letter == 'z' || letter == 'Z')
		{
			conversion = LetterValue::Z;
		}
		else if (letter == '1')
		{
			conversion = LetterValue::ONE;
		}
		else if (letter == '2')
		{
			conversion = LetterValue::TWO;
		}
		else if (letter == '3')
		{
			conversion = LetterValue::THREE;
		}
		else if (letter == '4')
		{
			conversion = LetterValue::FOUR;
		}
		else if (letter == '5')
		{
			conversion = LetterValue::FIVE;
		}
		else if (letter == '6')
		{
			conversion = LetterValue::SIX;
		}
		else if (letter == '7')
		{
			conversion = LetterValue::SEVEN;
		}
		else if (letter == '8')
		{
			conversion = LetterValue::EIGHT;
		}
		else if (letter == '9')
		{
			conversion = LetterValue::NINE;
		}
		else if (letter == '0')
		{
			conversion = LetterValue::ZERO;
		}
		else if (letter == '\'')
		{
			conversion = LetterValue::SINGLE_QUOTE;
		}
		else if (letter == '"')
		{
			conversion = LetterValue::DOUBLE_QUOTE;
		}
		else if (letter == ',')
		{
			conversion = LetterValue::COMMA;
		}
		else if (letter == '.')
		{
			conversion = LetterValue::PERIOD;
		}
		else if (letter == '?')
		{
			conversion = LetterValue::QUESTION;
		}
		else if (letter == '!')
		{
			conversion = LetterValue::EXCLAMATION;
		}
		else
		{
			conversion = LetterValue::INVALID;
		}

		return conversion;
	}

private:

	//Used to check if the letter is uppercased or not
	//Will be used to check if lower as well
	bool myIsUpper;

	char myChar;

	LetterValue myLetterValue;

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Class that implements mw::Char.  It can still = an std::string
class String
{
public:
	String(){};
	~String(){};

	//Operator methods

	String& String::operator= (const String& me)
	{
		// check for self-assignment by comparing the address of the
		// implicit object and the parameter
		if (this == &me)
			return *this;
 
		// do the copy
		myChars = me.myChars;
 
		// return the existing object
		return *this;
	}

	String& String::operator= (const std::string text)
	{
		// do the copy
		String::operator=(*this);
		this->setString(text);
 
		// return the existing object
		return *this;
	}

	//Accessor Methods

	mw::Char getChar(int index) 
	{ 
		if(index < myChars.size()) 
			return myChars[index]; 
		else
			return mw::Char();
	}

	//mutator methods

	void setString(std::string text)
	{
		myChars.clear();
		myString = text;

		for(int i = 0; i < text.size(); i++)
		{
			mw::Char tempChar;
			tempChar = text[i];
			myChars.push_back(tempChar);
		}
	}

	std::string const getString() { return myString; }

private:
	//Contains the list of character
	std::vector<mw::Char> myChars;

	//To get text for display and comparisons
	std::string myString;

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


} //end of namespace


namespace sf
{

namespace hud
{


class Text : public sf::Drawable
{
public:

	Text() 
	{
		myPosition.x = 0; 
		myPosition.y = 0; 

		myFontSize = 32;

		myText = "";

		myColor = sf::Color(255, 255, 255, 255);
	}
	~Text() {}

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

	/*
		- Converts the text given and creates the text image

		- automatically allignes text with itself.

		- "\n" will make the text go down a line past that point
	*/
	void setText(std::string text)
	{
		myText = text;

		int line = 0, letter = 0;

		int const LETTERS_PER_LINE = 10;
		int const LENGTH_WIDTH_PER_LETTER = 32;

		//Since there is new text, we must clear the old
		myLetterSprites.clear();

		//To make a new line
		std::vector<sf::Sprite> tempVector;

		//Make the first line to start writing too
		myLetterSprites.push_back(tempVector);

		/*
			Loop goes through all of the text
			and with each letter prepares the image
			in myLetterSprite.
		*/
		for(int i = 0; i < text.size(); i++)
		{
			//check if we want to go down a line
			if(myText.getChar(i).getChar() == '\n')
			{
				//Go down a line
				myLetterSprites.push_back(tempVector);

				//we added a line and a line starts at 0
				line++;
				letter = 0;
			}
			else
			{
				mw::Char tempChar;
				tempChar = text[i];

				//Add LetterSprite to the line
				myLetterSprites[myLetterSprites.size()-1].push_back(sf::Sprite());

				//This is temporary code 
				myLetterSprites[line][letter].setTexture(mw::Texture::hud::TEXTURE_TEXT);
				myLetterSprites[line][letter].setTextureRect(sf::IntRect((int)tempChar.getLetterValue() * LENGTH_WIDTH_PER_LETTER, 
																		 (int)((int)tempChar.getLetterValue() / LETTERS_PER_LINE), 
																		 32, 32));

				//we just added a letter so move the index
				letter++;
			}
		}

		setColor(myColor);
		setSize(myFontSize);

		allignText();
	}

	void setPosition(float x, float y)
	{
		myPosition.x = x;
		myPosition.y = y;

		if(myLetterSprites.size() > 0)
		{
			myLetterSprites[0][0].setPosition(x, y);
			allignText();
		}
	}

	void setColor(sf::Color color)
	{
		myColor = color;

		//Check each line
		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			//Check each letter in line
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				myLetterSprites[line][letter].setColor(myColor);
			}
		}
	}
	void setColorOfLine(sf::Color color, int line = 0)
	{
		if(line < myLetterSprites.size())
		{
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				myLetterSprites[line][letter].setColor(color);
			}
		}
	}
	void setColorOfLetter(sf::Color color, int line = 0, int letter = 0)
	{
		if(line < myLetterSprites.size())
		{
			if(letter < myLetterSprites[line].size())
			{
				myLetterSprites[line][letter].setColor(color);
			}
		}
	}

	void setSize(int fontSize) 
	{
		myFontSize = fontSize;

		//Check each line
		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			//Check each letter in line
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				myLetterSprites[line][letter].setScale(fontSize / TEXT_SIZE, fontSize / TEXT_SIZE);
			}
		}
	}

	//Special mutator methods

	/*
		Method that moves Text by the given amount for x and y
	*/
	void move(float x, float y)
	{
		setPosition(this->myPosition.x + x, this->myPosition.y + y);
	}

	// Accessor methods

	mw::String const getText() { return myText; }
	
	float getWidth() 
	{
		float size = 0;
		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			if(myLetterSprites[line].size() > 0)
			{
				//if size is less than the width of our text than...
				if(myLetterSprites[line][myLetterSprites[line].size()-1].getPosition().x + myLetterSprites[line][myLetterSprites[line].size()-1].getGlobalBounds().width
					- myLetterSprites[line][0].getPosition().x > size)
				{
					size = myLetterSprites[line][myLetterSprites[line].size()-1].getPosition().x + myLetterSprites[line][myLetterSprites[line].size()-1].getGlobalBounds().width
							- myLetterSprites[line][0].getPosition().x;
				}
			}
		}

		return size;
	}

	float getHeight() 
	{
		float size = 0;
		
		if(myLetterSprites.size() > 0)
		{
			if(myLetterSprites[myLetterSprites.size()-1].size() > 0)
			{
				size = myLetterSprites[myLetterSprites.size()-1][0].getPosition().y + 
						myLetterSprites[myLetterSprites.size()-1][0].getGlobalBounds().height - myPosition.y;
			}
			else
			{
				size = (myLetterSprites.size() * TEXT_SIZE) - myPosition.y;
			}
		}
		

		return size;
	}

private:
	//Method to help auto allign the rest of the text.
	//alligns the rest of the text with the first letter.
	//Use this if the first letter's position is moved or more text is added
	void allignText() 
	{
		//Make sure there is text to allign
		if(myLetterSprites.size() > 0)
		{
			//Go through each line
			for(int line = 0; line < myLetterSprites.size(); line++)
			{
				//Go through each letter in each line
				for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
				{
					//if we are passed the first line which has the acception of the first letter
					//then work normally
					if(line > 0)
					{
						//if we are pass the special position editing first letter
						if (letter > 0)
						{
							//Set letter position in allignment to the previous letter and height with the first letter of row.
							myLetterSprites[line][letter].setPosition(myLetterSprites[line][letter-1].getPosition().x + myLetterSprites[line][letter-1].getGlobalBounds().width,
																		myLetterSprites[line][0].getPosition().y);
						}
						else
						{
							//Prepare first letter in line
							myLetterSprites[line][letter].setPosition(myLetterSprites[0][letter].getPosition().x, 
																	  myLetterSprites[0][letter].getPosition().y + myLetterSprites[0][letter].getGlobalBounds().height * line);
						}
					}
					else
					{
						//Must ignore special exception of first letter
						//Work normally for the rest
						if(letter > 0)
						{
							//Set letter position in allignment to the previous letter and height with the first letter of row.
							myLetterSprites[line][letter].setPosition(myLetterSprites[line][letter-1].getPosition().x + myLetterSprites[line][letter-1].getGlobalBounds().width,
																		myLetterSprites[line][0].getPosition().y);
						}
					}
				}//end of for
			}//end of for
		}//end of if

	}//end of method

	//needed to make drawable (must be private)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		//Check each line
		for(int line = 0; line < myLetterSprites.size(); line++)
		{
			//Check each letter in line
			for(int letter = 0; letter < myLetterSprites[line].size(); letter++)
			{
				target.draw(myLetterSprites[line][letter], states);
			}
		}
	}

private:

	static const float TEXT_SIZE;

	//Contains the text for any comparison purposes
	mw::String myText;

	//Sprite arary that contains the letters
	//Will be read as myLetterSprites[Line][Letter] (aka [y][x])
	std::vector<std::vector<sf::Sprite>> myLetterSprites;

	//To ensure when a position is set, it will get there
	sf::Vector2f myPosition;

	//To save its color
	sf::Color myColor;

	//To save its fontSize
	int myFontSize;

}; //end of class Text

const float Text::TEXT_SIZE = 32.0f;

}//end of namespace hud

}//end of namespace sf