#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _sky,_cheetah, _forest, _cloud, _cloud1, _sun, _sand, _bird, _tree, _tree1;
	int _width_cloud, _width_sun, _sky_x, _sky_x2, _sun_x, _sun_y,
	_cloud_x, _cloud_x2, _cloud_x3, _cloud_x4, _cloud_x5, _cloud_x6,
	_sky_y, _forest_y, _cloud_y, _st_slow, _st_cloud, _st_sun,
	_st_fast, _st_tree, _sand_x, _sand_x2, _sand_y, _bird_x, _bird_y,
	_tree_x, _tree_x2, _tree_y, _cheetah_x, _cheetah_y,
	_tree1_x, _tree1_x2, _tree1_y;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};



#endif /* EXAMPLEWINDOW_H_ */
