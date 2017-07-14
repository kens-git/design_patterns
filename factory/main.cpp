#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;



class Widget {
    public:
        Widget(float price) { mPrice = price; }
        float getPrice() { return mPrice; }

    private:
        float mPrice;
};

class SteelWidget : public Widget {
    public:
        SteelWidget(float price) : Widget(price) { }
};

class GoldWidget : public Widget {
    public:
        GoldWidget(float price) : Widget(price) { }
};



enum WidgetType { STEEL, GOLD };

class WidgetFactory {
    public:
        unique_ptr<Widget> createWidget(WidgetType widgetType);

        // operation1()
        // operation2()
        // operation3()
        // etc...
};

unique_ptr<Widget> WidgetFactory::createWidget(WidgetType widgetType) {
    switch (widgetType) {
        case WidgetType::STEEL:
            return make_unique<SteelWidget>(2);

        case WidgetType::GOLD:
            return make_unique<GoldWidget>(7200);
    }
}

int main() {
    WidgetFactory theFactory;
    unique_ptr<Widget> myWidget = theFactory.createWidget(WidgetType::GOLD);

    cout << "My gold widget is worth $" << myWidget->getPrice() << endl;

    myWidget = theFactory.createWidget(WidgetType::STEEL);

    cout << "My steel widget is worth a measly $" << myWidget->getPrice() << endl;

    return 0;
}
