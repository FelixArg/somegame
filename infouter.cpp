#include "infouter.h"

bool infouter::fout(std::string filename, std::vector<world*> worlds) {
	std::ofstream stream;
	stream.open(filename, std::ios::out);
	if (!stream.is_open())
		return false;
	for (world* w : worlds) {
		stream << "world" << std::endl;
		stream << "width " << w->get_width() << std::endl;
		stream << "height " << w->get_height() << std::endl;
		for (object* o : w->objects) {
			stream << "object" << std::endl;
			stream << "type " << o->to_string() << std::endl;
			stream << "id " << o->get_id() << std::endl;
			stream << "position " << o->get_position_x() << ' ' << o->get_position_y() << std::endl;
			stream << "size " << o->get_size() << std::endl;
			stream << "faceangle " << o->get_face_angle() << std::endl;
			if (dynamic_cast<idestroyable*>(o))
				stream << "destroyable " << dynamic_cast<idestroyable*>(o)->get_durability() << std::endl;
			else
				stream << "undestroyable" << std::endl;
			stream << "endobject" << std::endl;
		}
		stream << "endworld" << std::endl;
	}
	stream.close();
}