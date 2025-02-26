

namespace util::geometry
{

// size = *{w, h}
dim& dim::operator=(const dim &rhs)
{
	this->width		= rhs.width;
	this->height	= rhs.height;
	this->length	= rhs.length;
	return *this;
}

// size = {w, h}
dim& dim::operator=(const dim *rhs)
{
	this->width		= rhs->width;
	this->height	= rhs->height;
	this->length	= rhs->length;
	return *this;
}

}

