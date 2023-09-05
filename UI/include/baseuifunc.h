/*****************************************************************//**
 * \file   baseuifunc.h
 * \brief  BaseUI 公共接口 
 * 
 * \author shijiaobing
 * \date   September 2023
 *********************************************************************/


#ifndef  _BASE_UI_FUNC_H_
#define  _BASE_UI_FUNC_H_
#include <QObject>
class BaseUIFunc :public QObject{
	Q_OBJECT
public:
	virtual void initBaseUI()=0;
	virtual void close() = 0;

};

#endif // _BASE_UI_FUNC_H_




