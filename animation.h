
#ifndef _ANIMATON_H_
#define _ANIMATON_H_

#include <QPropertyAnimation>

QPropertyAnimation *create(QObject *object,
                    const QByteArray& propertyName,
                    QVariant const &startValue,
                    QVariant const &endValue,
                    int duration = 200);

#endif
