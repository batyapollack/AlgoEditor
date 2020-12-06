#include "InputButton.h"
#include "Board.h"

InputButton::InputButton(Board& board)
    :Button(board)
{
    m_sprite.setPosition(OBS_INPUT);
    m_sprite.setTexture(MediaSource::instance().getTexture(INPUT_P));
    m_float_rect = m_sprite.getGlobalBounds();
    
}

ButtonType InputButton::getBtnType()
{
    return INPUT_T;
}

void InputButton::execute(sf::Vector2i loc)
{
    WindowInput windowInput;
    windowInput.getInput();
    m_board.read(windowInput.getNumber());

    
}
