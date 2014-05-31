#ifndef __SHM_H_INCLUDED__
#define __SHM_H_INCLUDED__

#include "Proxy.h"

class Shm : public Proxy
{
public:
	using Proxy::Proxy;

	enum error {
		WL_SHM_ERROR_INVALID_FORMAT = 0, 
		WL_SHM_ERROR_INVALID_STRIDE = 1, 
		WL_SHM_ERROR_INVALID_FD = 2
	};
	enum format {
		WL_SHM_FORMAT_ARGB8888 = 0, 
		WL_SHM_FORMAT_XRGB8888 = 1, 
		WL_SHM_FORMAT_C8 = 0x20203843, 
		WL_SHM_FORMAT_RGB332 = 0x38424752, 
		WL_SHM_FORMAT_BGR233 = 0x38524742, 
		WL_SHM_FORMAT_XRGB4444 = 0x32315258, 
		WL_SHM_FORMAT_XBGR4444 = 0x32314258, 
		WL_SHM_FORMAT_RGBX4444 = 0x32315852, 
		WL_SHM_FORMAT_BGRX4444 = 0x32315842, 
		WL_SHM_FORMAT_ARGB4444 = 0x32315241, 
		WL_SHM_FORMAT_ABGR4444 = 0x32314241, 
		WL_SHM_FORMAT_RGBA4444 = 0x32314152, 
		WL_SHM_FORMAT_BGRA4444 = 0x32314142, 
		WL_SHM_FORMAT_XRGB1555 = 0x35315258, 
		WL_SHM_FORMAT_XBGR1555 = 0x35314258, 
		WL_SHM_FORMAT_RGBX5551 = 0x35315852, 
		WL_SHM_FORMAT_BGRX5551 = 0x35315842, 
		WL_SHM_FORMAT_ARGB1555 = 0x35315241, 
		WL_SHM_FORMAT_ABGR1555 = 0x35314241, 
		WL_SHM_FORMAT_RGBA5551 = 0x35314152, 
		WL_SHM_FORMAT_BGRA5551 = 0x35314142, 
		WL_SHM_FORMAT_RGB565 = 0x36314752, 
		WL_SHM_FORMAT_BGR565 = 0x36314742, 
		WL_SHM_FORMAT_RGB888 = 0x34324752, 
		WL_SHM_FORMAT_BGR888 = 0x34324742, 
		WL_SHM_FORMAT_XBGR8888 = 0x34324258, 
		WL_SHM_FORMAT_RGBX8888 = 0x34325852, 
		WL_SHM_FORMAT_BGRX8888 = 0x34325842, 
		WL_SHM_FORMAT_ABGR8888 = 0x34324241, 
		WL_SHM_FORMAT_RGBA8888 = 0x34324152, 
		WL_SHM_FORMAT_BGRA8888 = 0x34324142, 
		WL_SHM_FORMAT_XRGB2101010 = 0x30335258, 
		WL_SHM_FORMAT_XBGR2101010 = 0x30334258, 
		WL_SHM_FORMAT_RGBX1010102 = 0x30335852, 
		WL_SHM_FORMAT_BGRX1010102 = 0x30335842, 
		WL_SHM_FORMAT_ARGB2101010 = 0x30335241, 
		WL_SHM_FORMAT_ABGR2101010 = 0x30334241, 
		WL_SHM_FORMAT_RGBA1010102 = 0x30334152, 
		WL_SHM_FORMAT_BGRA1010102 = 0x30334142, 
		WL_SHM_FORMAT_YUYV = 0x56595559, 
		WL_SHM_FORMAT_YVYU = 0x55595659, 
		WL_SHM_FORMAT_UYVY = 0x59565955, 
		WL_SHM_FORMAT_VYUY = 0x59555956, 
		WL_SHM_FORMAT_AYUV = 0x56555941, 
		WL_SHM_FORMAT_NV12 = 0x3231564e, 
		WL_SHM_FORMAT_NV21 = 0x3132564e, 
		WL_SHM_FORMAT_NV16 = 0x3631564e, 
		WL_SHM_FORMAT_NV61 = 0x3136564e, 
		WL_SHM_FORMAT_YUV410 = 0x39565559, 
		WL_SHM_FORMAT_YVU410 = 0x39555659, 
		WL_SHM_FORMAT_YUV411 = 0x31315559, 
		WL_SHM_FORMAT_YVU411 = 0x31315659, 
		WL_SHM_FORMAT_YUV420 = 0x32315559, 
		WL_SHM_FORMAT_YVU420 = 0x32315659, 
		WL_SHM_FORMAT_YUV422 = 0x36315559, 
		WL_SHM_FORMAT_YVU422 = 0x36315659, 
		WL_SHM_FORMAT_YUV444 = 0x34325559, 
		WL_SHM_FORMAT_YVU444 = 0x34325659
	};
	ShmPool *create_pool(uint32_t fd, int32_t size) {
		return new ShmPool(marshal_constructor(WL_SHM_CREATE_POOL, &wl_shm_pool_interface, NULL, fd, size));
	}
};

#endif