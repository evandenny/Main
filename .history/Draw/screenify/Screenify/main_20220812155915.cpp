#include <assert.h>

#include "Screen.hpp"

int main() {
	// Top left of screen: (0, 0)
	
	auto s = new Screen(20, 15); // 20x15 screen
	
	s->outline_border(); // Using default params
	
	s->draw_rect('#', // The fill character
				 7, 12, // Point 1
				 10, 13, // Point 2
				 true); // Fill rectangle
	
	// More efficient for writing large batches of coordinates.
	// This block is run over all coordinates in the screen, and returns a character.
	// You can get the existing value at a coordinate using the `value_at(x, y)` function.
	// The macro `SCREEN_COORDINATE_PARAMS` is equivalent to `size_t x, size_t y`.
	//
	// s->write_batch([](SCREEN_COORDINATE_PARAMS) {
	//     if (y >= 12)
	//         return '*';
	//
	//     return s->value_at(x, y); // The old value. Efficient because of diff-checking
	// });
}
