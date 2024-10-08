#ifndef WIDGET_PROFILE_H
#define WIDGET_PROFILE_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

class Profile : public QWidget {
    Q_OBJECT


public:
    /* imagePath 설정 필요 */
    explicit Profile(const QString& name, const QString& imagePath, QWidget *parent = nullptr);

private:
    QLabel *profileImage;
    QLabel *profileName;
    QPushButton *viewProfileInfo();

private slots:
    void showProfileInfo();
};

#endif // WIDGET_PROFILE_H
