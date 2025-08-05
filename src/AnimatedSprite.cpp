#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite() {}

void AnimatedSprite::setTexture(const sf::Texture &texture) {
  m_texture = &texture;
  m_sprite.emplace(texture);
}

void AnimatedSprite::setFrameSize(sf::Vector2i frameSize) {
  m_frameSize = frameSize;
  m_sprite->setTextureRect({{0, 0}, m_frameSize});
}

void AnimatedSprite::setNumFrames(std::size_t numFrames) {
  m_numFrames = numFrames;
}

void AnimatedSprite::setDuration(float duration) {
  m_duration = duration;
}

void AnimatedSprite::setLooping(bool loop) {
  m_isLooping = loop;
}

void AnimatedSprite::play() {
  m_isPlaying = true;
}

void AnimatedSprite::stop() {
  m_isPlaying = false;
}

void AnimatedSprite::reset() {
  m_elapsed = 0.0f;
  m_currentFrame = 0;
  m_sprite->setTextureRect({{0, 0}, m_frameSize});
}

void AnimatedSprite::update(float dt) {
  if (!m_isPlaying || m_numFrames == 0 || m_duration <= 0.0f) return;

  m_elapsed += dt;
  float timePerFrame = m_duration / static_cast<float>(m_numFrames);

  while (m_elapsed >= timePerFrame) {
    m_elapsed -= timePerFrame;
    m_currentFrame++;

    if (m_currentFrame >= m_numFrames) {
      if (m_isLooping) {
        m_currentFrame = 0;
      } else {
        m_currentFrame = m_numFrames - 1;
        m_isPlaying = false;
      }
    }

    int frameX = (m_currentFrame * m_frameSize.x) % m_texture->getSize().x;
    int frameY = ((m_currentFrame * m_frameSize.x) / m_texture->getSize().x) * m_frameSize.y;
    m_sprite->setTextureRect({{frameX, frameY}, m_frameSize});
  }
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform(); // apply position/scale/rotation
  target.draw(*m_sprite, states);
}

