#ifndef MAPNIK_GENERATE_IMAGE_H_FILE
#define MAPNIK_GENERATE_IMAGE_H_FILE

#pragma warning(disable:4068)

#include <mapnik/map.hpp>
#include <QtCore>

bool GenerateImage(mapnik::Map mapOut, const char* sOutFileName);

bool LoadXML2Map(const char* sMapXmlDir, QList<mapnik::Map>& mvMaps, int nImgSize);

bool LoadLocation(const char* sLocationFile, QList<QString>& svAllPoints);

bool GeneratePerLocOneImage(
	const char* sDataSourceDir,//����Դ���λ�ã�Ϊmapnik���lib�ļ����е�input�ļ���
	const char* sMapXmlDir,    //xml�ļ���
	const char* sLocationFile, //��γ���б��ļ�
	const char* sSaveImageDir, //����ͼƬ����ļ���
	int nImageSize,            //�����ͼƬ��С
	double dSquareDis,         //�����Χ�뾶��С(m)
	int nStartFID,             //������ĸ�FID�ľ�γ�ȿ�ʼ����
	int nHashPrecision,        //����ļ�����GeoHash����
	int nThreadsNum            //ʹ�ö��ٸ��߳̽������
);

bool GeneratePerLocMultiImage(
	const char* sDataSourceDir,
	const char* sMapXmlDir,
	const char* sLocationFile,
	const char* sSaveImageDir,
	int nImageSize,
	double dSquareDis,
	int nStartFID,
	int nHashPrecision,
	int nThreadsNum,
	int nRandImageNum
);

// ��ͼƬ����ʱ��ÿ��ѵ������ʱ����Ҫ�ܳ�ʱ�䣬���Խ�����ͼƬ���ļ��������ļ���
bool OutputObjectList(const char* sImageDir, const char* sObjectListFile);

// ��������ͼƬ�Ƿ���ȱ©
bool CheckPerLocOneImageResult(const char* sSaveImageDir, const char* sLocationFile, int nImageLayer, int nHashPrecision, const char* sMissingLocFile);

// ��������ͼƬ�Ƿ���ȱ©
bool CheckPerLocMultiImageResult(const char* sSaveImageDir, const char* sLocationFile, int nImageLayer, int nHashPrecision, int nRandImageNum, const char* sMissingLocFile);

bool CheckPerLocMultiImageResult(const char* sLabelFile, const char* sObjectListFile, const char* sMissingFile);


// ��˳������label
bool outputLabelFile(const char* sLocFile, const char* sLabelFile);


#endif
