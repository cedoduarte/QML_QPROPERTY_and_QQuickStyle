#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickStyle>
#include "myperson.h"

// Styles:
// -> Material
// -> Imagine
// -> Universal
// -> Fusion

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQuickStyle::setStyle("Fusion");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QObjectList people; // personas
    people.append(new MyPerson("Juan", 20));
    people.append(new MyPerson("Ana", 25));
    people.append(new MyPerson("Luis", 30));
    people.append(new MyPerson("Maria", 40));
    people.append(new MyPerson("Pedro", 35));
    people.append(new MyPerson("Carlos", 45));
    people.append(new MyPerson("Alicia", 19));

    engine.rootContext()->setContextProperty("people", QVariant::fromValue(people));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }
    return app.exec();
}
