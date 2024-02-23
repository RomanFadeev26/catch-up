#pragma once
#include <vector>
#include "SDL.h"
#include "Window.h"
#include "IPresentationBuilder.h"


class RenderEngine
{
	public:
		RenderEngine(RenderEngine&) = delete;
		void operator=(const RenderEngine&) = delete;
		~RenderEngine();
		static RenderEngine* getInstance();
		static void destroyInstance();
		void addSprite(IPresentationBuilder::FieldItemPresentation);
		void addAnimation(IPresentationBuilder::FieldItemPresentation, int);
		void setColor(SDL_Color color);
		SDL_Renderer* getRenderer() const;
		const Window& getWindow() const;
		void render();
		struct Frame {
			IPresentationBuilder::FieldItemPresentation presentation_;
			SDL_Rect src_;
			int frame_;
			int fps_;
		};
		static constexpr int FRAMES_PER_SECOND = 60;
		static constexpr int DEFAULT_WINDOW_WIDTH = 640;
		static constexpr int DEFAULT_WINDOW_HEIGHT = 480;
	private:
		static RenderEngine* instance_;
		RenderEngine();
		void renderSprites() const;
		void renderAnimations();
		SDL_Renderer* renderer_ = nullptr;
		Window window_ = Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
		std::vector<IPresentationBuilder::FieldItemPresentation> sprites_;
		std::vector<Frame> animations_;
		int currentFrame_ = 0;
};

