#include "MediaSource.h"
#include <iostream>

const std::vector<std::string> PICTURE_BTN = { "route.png","brick.png","delete.png","refresh.png" , "back_button.png","input.png","circle.png"};
const std::vector<std::string> PICTURE_BTN_MOUSE_OVER = { "route_mouse_over.png","brick_mouse_over.png","delete_mouse_over.png","refresh_mouse_over.png","back_button_mouse_over.png","input_mouse_over.png","circle.png" };


MediaSource& MediaSource::instance()
{
	static MediaSource instance;
	return instance;
}

const sf::Texture& MediaSource::getTexture(PICTURES_TYPE i) const
{
	return m_textures[i];
}

const sf::Texture& MediaSource::getTextureHighlight(PICTURES_TYPE index) const
{
	return m_texturesHighlight[index];
}

const sf::Font& MediaSource::getFont() const
{
	return m_font;
}

MediaSource::MediaSource()
{
	loadTexture();
	m_font.loadFromFile("font.ttf");

}

void MediaSource::loadTexture()
{
	m_textures.resize(PICTURE_BTN.size());
	m_texturesHighlight.resize(PICTURE_BTN_MOUSE_OVER.size());
	for (int i = 0; i < m_textures.size(); i++)
		if (!( m_textures[i].loadFromFile(PICTURE_BTN[i]) &&
			m_texturesHighlight[i].loadFromFile(PICTURE_BTN_MOUSE_OVER[i]) ) )
		{
			std::cout << "Cannot allocate the texture";
			exit(EXIT_FAILURE);
		}
}

