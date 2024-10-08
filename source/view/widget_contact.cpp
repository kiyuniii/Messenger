#include "widget_contact.h"


Profile::Profile(const QString& imagePath, const QString& name, QWidget *parent)
    : QWidget(parent)
{
    QFrame *frame = new QFrame(this);
    frame->setFrameShape(QFrame::Box);
    frame->setFrameShadow(QFrame::Raised);
    frame->setStyleSheet("background-color: #f0f0f0; border-radius: 10px; padding: 10px;");

    QLabel *profileImage = new QLabel(this);
    profileImage->setPixmap(QPixmap(imagePath).scaled(100, 100, Qt::KeepAspectRatio));
    profileImage->setAlignment(Qt::AlignCenter);

    QLabel *profileName = new QLabel(name, this);
    profileName->setAlignment(Qt::AlignCenter);

    QPushButton *viewProfileButton = new QPushButton("View Profile", this);
    connect(viewProfileButton, &QPushButton::clicked, this, &Profile::showProfileInfo);

    /* Layout 설정 */
    QHBoxLayout *layout = new QHBoxLayout(frame);
    layout->addWidget(profileImage);
    layout->addWidget(profileName);
    layout->addWidget(viewProfileButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(frame);
    setLayout(mainLayout);
}

void Profile::showProfileInfo() {
    QMessageBox::information(this, "user Info", " ... ");
}
