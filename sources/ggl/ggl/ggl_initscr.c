#include <hpgcc49.h>

#include "gglpr.h"


void ggl_initscr(gglsurface *srf)
{
srf->addr=(int *)sys_map_v2p((int)sys_phys_malloc(BUFSIZE<<1));
srf->width=LCD_W;
srf->x=srf->y=0;
}
