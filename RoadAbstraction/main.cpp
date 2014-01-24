/**
 * 道路網の中で、一定距離以上のエッジのみ残す。
 *
 * @author Gen Nishida
 * @version 1.0
 */

#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "GraphUtil.h"
#include "BBox.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Usage: RoadFeature <GSM file>" << std::endl;
		return 1;
	}

	RoadGraph r;
	GraphUtil::loadRoads(r, argv[1]);

	GraphUtil::extractMajorRoads(r, 500);

	GraphUtil::saveRoads(r, "result.gsm");

}