#ifndef RENDERSETTING_H
#define RENDERSETTING_H

#include <QDialog>
#include "ui_rendersetting.h"

class RenderSetting : public QDialog
{
	Q_OBJECT

public:
	RenderSetting(QWidget *parent = 0);
	~RenderSetting();

private:
	Ui::RenderSetting ui;
};

#endif // RENDERSETTING_H
