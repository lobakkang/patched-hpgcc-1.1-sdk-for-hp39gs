#include <hpgcc49.h>
#include <hpgraphics.h>

#include "gglpr.h"
#include "../../hpg/common/hpgpriv.h"


void ggl_gethpgscreen(gglsurface *srf)
{
srf->addr=(int *)hpg_stdscreen->drawfb;
// HPG USES WIDTH IN BYTES, ASSUME 16-GRAYS MODE = 2 PIXELS/BYTE
srf->width=hpg_stdscreen->fbwidth*2;
srf->x=srf->y=0;
}
