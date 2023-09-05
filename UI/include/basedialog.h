/*****************************************************************//**
 * \file   baseDialog.h
 * \brief  
 * 
 * \author shijiaobing
 * \date   September 2023
 *********************************************************************/

#ifndef _BASE_DIALOG_H_
#define _BASE_DIALOG_H_
#include  <QDialog>
#include <QObject>
#include "ui_global.h"
#include "baseuifunc.h"

class UI_EXPORT BaseDialog : public  QDialog ,public BaseUIFunc{
	Q_OBJECT
public:
	explicit BaseDialog(QWidget* parent = nullptr);




protected:

};

#endif // _BASE_DIALOG_H_