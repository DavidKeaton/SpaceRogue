

namespace util::geometry
{

dimensions& dimensions::operator=(const dimensions &rhs)
{
	this->width		= rhs.width;
	this->height	= rhs.height;
	this->length	= rhs.length;
	return *this;
}

}

