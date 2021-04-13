#include "ExampleWindow.h"

#include <stdexcept>
#include <SDL2/SDL_image.h>

ExampleWindow::ExampleWindow(int width, int height) :
		Window(width, height),
		 _width_cloud(width / 4), _width_sun(width/2.5), _sky_x(0), _sky_x2(width), _sun_x(width), _sun_y(-height/15),
		_cloud_x(width), _cloud_x2(width + _width_cloud), _cloud_x3(width + _width_cloud *2),
		_cloud_x4(width + _width_cloud *3), _cloud_x5(width + _width_cloud * 4), _cloud_x6(width + _width_cloud * 5),
		_sky_y(0), _forest_y(height / 5), _cloud_y(height / 90), _st_slow(1), _st_cloud(3), _st_sun(2),
		_st_fast(4), _st_tree(2), _sand_x(1), _sand_x2(width), _sand_y(height/5*3), _bird_x(0), _bird_y(height/8),
		_tree_x(width/15), _tree_x2(width*12/15), _tree_y(height/2.3), _cheetah_x(0), _cheetah_y(height/2),
		_tree1_x(width/8), _tree1_x2(width/8*7), _tree1_y(height/2.1){
	_sky = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sky.jpg"), SDL_DestroyTexture);
	if (_sky == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить небо ")
						+ std::string(SDL_GetError()));
	_forest = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "forest.png"), SDL_DestroyTexture);
			if (_forest == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить лес ")
								+ std::string(SDL_GetError()));
	_cloud = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud.png"), SDL_DestroyTexture);
	_cloud1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cloud1.png"), SDL_DestroyTexture);
			if (_cloud == nullptr || _cloud1 == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить облака ")
						+ std::string(SDL_GetError()));
	_sun = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sun.png"), SDL_DestroyTexture);
	if (_sun == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить солнце ")
						+ std::string(SDL_GetError()));
	_sand = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "sand.png"), SDL_DestroyTexture);
	if (_sand == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить песок ")
						+ std::string(SDL_GetError()));
	_bird = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "bird.png"), SDL_DestroyTexture);
	if (_bird == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить птицу ")
						+ std::string(SDL_GetError()));
	_tree = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "tree.png"),
			SDL_DestroyTexture);
	_tree1 = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "tree1.png"),
			SDL_DestroyTexture);
	if (_tree == nullptr || _tree1 == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить деревья ")
						+ std::string(SDL_GetError()));
	_cheetah = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "cheetah.png"),
			SDL_DestroyTexture);
	if (_cheetah == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить гепарда ")
						+ std::string(SDL_GetError()));
}

void ExampleWindow::render() {
	SDL_SetRenderDrawColor(_renderer.get(), 32, 32, 96, 255);
	SDL_RenderClear(_renderer.get());

	SDL_Rect sky_rect { _sky_x, _sky_y, width(), (height() / 2 + height() / 10) };
	SDL_Rect sky_rect2 { _sky_x2, _sky_y, width(), (height() / 2 + height() / 10) };
	SDL_Rect forest_rect { _sky_x, _forest_y, width(), height() / 2 };
	SDL_Rect forest_rect2 { _sky_x2, _forest_y, width(), height() / 2 };
	SDL_Rect tree_rect{ _tree_x, _tree_y, width()/5, height()/4};
	SDL_Rect tree_rect2{ _tree_x2, _tree_y, width()/5, height()/4};
	SDL_Rect cheetah_rect{ _cheetah_x, _cheetah_y, width()/3, height()/3};
	SDL_Rect tree1_rect{ _tree1_x, _tree1_y, width()/2, height()/2};
	SDL_Rect tree1_rect2{ _tree1_x2, _tree1_y, width()/2, height()/2};
	SDL_Rect cloud_rect { _cloud_x, _cloud_y + 100, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect2 { _cloud_x2, _cloud_y + 180, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect3 { _cloud_x3, _cloud_y + 50, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect4 { _cloud_x4, _cloud_y + 180, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect5 { _cloud_x5, _cloud_y + 50, _width_cloud, height() / 7 };
	SDL_Rect cloud_rect6 { _cloud_x6, _cloud_y + 180, _width_cloud, height() / 7 };
	SDL_Rect sun_rect{ _sun_x, _sun_y, _width_sun, _width_sun};
	SDL_Rect sand_rect{ _sand_x, _sand_y, width(), height()/2};
	SDL_Rect sand_rect2{ _sand_x2, _sand_y, width(), height()/2};
	SDL_Rect bird_rect{ _bird_x, _bird_y, width()/5, height()/6};

	SDL_RenderCopy(_renderer.get(), _sky.get(), nullptr, &sky_rect);
	SDL_RenderCopyEx(_renderer.get(), _sky.get(), nullptr, &sky_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect2);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect4);
	SDL_RenderCopy(_renderer.get(), _cloud1.get(), nullptr, &cloud_rect6);
	SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun_rect);
	SDL_RenderCopy(_renderer.get(), _forest.get(), nullptr, &forest_rect);
	SDL_RenderCopyEx(_renderer.get(), _forest.get(), nullptr, &forest_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect5);
	SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect3);
	SDL_RenderCopy(_renderer.get(), _sand.get(), nullptr, &sand_rect);
	SDL_RenderCopyEx(_renderer.get(), _sand.get(), nullptr, &sand_rect2, 0, nullptr, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree_rect);
	SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree_rect2);
	SDL_RenderCopy(_renderer.get(), _bird.get(), nullptr, &bird_rect);
	SDL_RenderCopy(_renderer.get(), _cheetah.get(), nullptr, &cheetah_rect);
	SDL_RenderCopy(_renderer.get(), _tree1.get(), nullptr, &tree1_rect);
	SDL_RenderCopy(_renderer.get(), _tree1.get(), nullptr, &tree1_rect2);

}

void ExampleWindow::do_logic() {
	_sky_x -= _st_slow;
	_sky_x2 -= _st_slow;
	_cloud_x -= _st_cloud;
	_cloud_x2 -= _st_cloud;
	_cloud_x3 -= _st_cloud;
	_cloud_x4 -= _st_cloud;
	_cloud_x5 -= _st_cloud;
	_cloud_x6 -= _st_cloud;
	_sun_x -= _st_sun;
	_sand_x -= _st_slow;
	_sand_x2 -= _st_slow;
	_bird_x += _st_fast;
	_tree_x -= _st_tree;
	_tree_x2 -= _st_tree;
	_cheetah_x += _st_fast;
	_tree1_x -= _st_fast;
	_tree1_x2 -= _st_fast;
	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_bird_x > width()) {
		_bird_x = -width();
	}
	if (_tree_x <= 0 - width()/4) {
		_tree_x = width();
	}
	if (_tree_x2 <= 0 - width()/4) {
		_tree_x2 = width();
	}
	if (_cheetah_x > width()) {
		_cheetah_x = -width()/2;
	}
	if (_tree1_x <= 0 - width()/2) {
		_tree1_x = width();
	}
	if (_tree1_x2 <= 0 - width()/2) {
		_tree1_x2 = width();
	}
	if (_cloud_x <= -_width_cloud) {
		_cloud_x = width();
	}
	if (_cloud_x2 <= -_width_cloud) {
		_cloud_x2 = width();
	}
	if (_cloud_x3 <= -_width_cloud) {
		_cloud_x3 = width();
	}
	if (_cloud_x4 <= -_width_cloud) {
		_cloud_x4 = width();
	}
	if (_cloud_x5 <= -_width_cloud) {
		_cloud_x5 = width();
	}
	if (_cloud_x6 <= -_width_cloud) {
		_cloud_x6 = width();
	}
	if (_sun_x <= 0-_width_sun) {
		_sun_x = width();
	}
	if (_sky_x <= 0 - width()) {
		_sky_x = width();
	}
	if (_sky_x2 <= 0 - width()) {
		_sky_x2 = width();
	}
	if (_sand_x <= 0 - width()) {
		_sand_x = width();
	}
	if (_sand_x2 <= 0 - width()) {
		_sand_x2 = width();
	}
}

void ExampleWindow::handle_keys(const Uint8 *keys) {
	if (keys[SDL_SCANCODE_DOWN] && _bird_y < (_sand_y + (height()/100)/180))
		_bird_y += 5;
	if (keys[SDL_SCANCODE_UP] && _bird_y > (_sand_y - (height()/3))/180)
		_bird_y -= 5;
}


