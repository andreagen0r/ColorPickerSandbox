#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace Qt::Literals;

int main( int argc, char* argv[] ) {

    QGuiApplication app( argc, argv );

    QQmlApplicationEngine engine;

    engine.addImportPath(":/origin/qml"_L1);
    engine.addImportPath(":/colorpicker/qml"_L1);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit( -1 ); }, Qt::QueuedConnection );
    engine.loadFromModule( "Sandbox"_L1, "Main"_L1 );

    return QGuiApplication::exec();
}
