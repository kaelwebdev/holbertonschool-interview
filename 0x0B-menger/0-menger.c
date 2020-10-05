#include "menger.h"

/**
 * add_space - check space.
 * @r: row idx
 * @c: col idx
 * Return: 1 | 0
*/
static int add_space(size_t r, size_t c)
{
	for (; r && c; r /= 3, c /= 3)
		if (r % 3 == 1 && c % 3 == 1)
			return (1);
	return (0);
}

/**
 * menger - create menger sponge (2D)
 * @level: Level of menger cube
 */
void menger(int level)
{
	size_t s, r, c;

	if (level < 0)
		return;

	s = pow(3, level);

	for (r = 0; r < s; ++r)
	{
		for (c = 0; c < s; ++c)
			printf(add_space(r, c) ? " " : "#");
		printf("\n");
	}

}
