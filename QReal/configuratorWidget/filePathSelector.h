#pragma once
#include <QtGui/QFrame>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

namespace pluginManager {

class FilePathSelector : public QFrame
{
	Q_OBJECT

public:
	explicit FilePathSelector(QWidget *parent = 0);
	void setFilePath(QString const &filePath);

private:
	QLineEdit *mFilePathEdit;
	QPushButton *mBrowseButton;
};

}
