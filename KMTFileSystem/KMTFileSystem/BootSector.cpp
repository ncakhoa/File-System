#include "BootSector.h"


void BootSector::createBootSector(uint64_t size_of_vol)
{
	Byte_Per_Sector = 512;
	Sector_Per_Cluster = 8;
	Total_Sector = size_of_vol * 1024 * 2;
	Total_Cluster = Total_Sector / 8;
	Sector_Begin_Of_CM = 1;
	Sector_Begin_RDET = 2 + Total_Cluster / 512 / 8;
}
void BootSector::write(fstream &Vol)
{
	Vol.write((char *)&label[0], 8 * sizeof(char));
	Vol.write((char *)&Byte_Per_Sector, sizeof(uint32_t));
	Vol.write((char *)&Sector_Per_Cluster, sizeof(uint32_t));
	Vol.write((char *)&Total_Sector, sizeof(uint64_t));
	Vol.write((char *)&Sector_Begin_Of_CM, sizeof(uint32_t));
	Vol.write((char *)&Sector_Begin_RDET, sizeof(uint32_t));
	Vol.write((char *)&cr[0], cr.size() * sizeof(char));
	Vol.write((char *)&End_Marker, sizeof(uint16_t));
}
uint64_t BootSector::getTotalCluster()
{
	return Total_Cluster;
}