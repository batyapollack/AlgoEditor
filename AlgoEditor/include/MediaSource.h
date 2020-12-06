#pragma once
#include "Macros.h"
#include <string>




class MediaSource
{
public:
	static MediaSource& instance();//return single instance
	~MediaSource() {};//Dtor of MediaSource
	const sf::Texture& getTexture(PICTURES_TYPE index)const; //return type pic
	const sf::Texture& getTextureHighlight(PICTURES_TYPE index)const; //return type pic
	const sf::Font& getFont()const;
private:
	MediaSource();//Ctor
	void loadTexture();
	MediaSource(const MediaSource&) = delete;//delete Copy Ctor
	MediaSource& operator = (const MediaSource&) = delete;// delete Assignment operator

	std::vector<sf::Texture> m_textures; //m_textures
	std::vector<sf::Texture> m_texturesAlgo; //m_textures
	std::vector<sf::Texture> m_texturesHighlight; //m_textures
	sf::Font m_font;


};

