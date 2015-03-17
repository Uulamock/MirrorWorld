#pragma once

namespace mw
{
	namespace Texture
	{

		/*
			Class simply designed to make it possible to load textures
			as extern const
		*/
		class ConstructorTexture : public sf::Texture
		{
		public:
			ConstructorTexture():sf::Texture(){}
			ConstructorTexture(const std::string &fileName):sf::Texture()
			{ 
				if(!loadFromFile(fileName))
				{
					//error
				}
			}
			~ConstructorTexture(){}
		};

	}//end of namespace Texture

}//end of namespace mw