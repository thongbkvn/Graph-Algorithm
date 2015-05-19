#include <QPropertyAnimation>

QPropertyAnimation *create(QObject *object,
                    const QByteArray& propertyName,
                    QVariant const &startValue,
                    QVariant const &endValue,
                    int duration = 2000)
{
    QPropertyAnimation *anim = new QPropertyAnimation(object, propertyName);
    anim->setDuration(duration);
    anim->setStartValue(startValue);
    anim->setEndValue(endValue);

    return anim;
}
