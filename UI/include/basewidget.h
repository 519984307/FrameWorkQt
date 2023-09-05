/*****************************************************************//**
 * \file   baseWidget.h
 * \brief  Widget »ùÀà
 * 
 * \author shijiaobing
 * \date   September 2023
 *********************************************************************/

#ifndef _BASE_WIDGET_H_
#define _BASE_WIDGET_H_
#include "ui_global.h"
#include "baseuifunc.h"
#include <QWidget>
class UI_EXPORT  BaseWidget :public QWidget ,public BaseUIFunc{

	Q_OBJECT
public:
	explicit BaseWidget(QWidget* parent = nullptr);





protected:
	virtual void initBaseUI()override;
	virtual void close()override;



};
#endif // !_BASE_WIDGET_H_
