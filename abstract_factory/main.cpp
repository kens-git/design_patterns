#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


// Generally we would subclass Widget with each specific type of widget, but, for the sake of brevity
// just use one generic Widget with different properties.
class Widget {
	public:
        void description() { cout << "The " << mName << " costs $" << mPrice << ", is made of " << mMaterial << ", " << mAssemblyDescription
									<< " and packaged in " << mPackageDescription << "." << endl; }
		
		void setPrice(unsigned int price) { mPrice = price; }
		void setName(const string& name) { mName = name; }
		void setMaterial(const string& material) { mMaterial = material; }
		void setAssemblyDescription(const string& assembly) { mAssemblyDescription = assembly; }
		void setPackageDescription(const string& package) { mPackageDescription = package; }
		
	protected:
		unsigned int mPrice;
		string mName;
		string mMaterial;
		string mAssemblyDescription;
		string mPackageDescription;
};

class WidgetFactory {
	public:
        virtual Widget createWidget() = 0;
};

class FancyWidgetFactory : public WidgetFactory {
	public:
        Widget createWidget() override { Widget widget;
												widget.setPrice(10000); widget.setName("Fancy Widget"); widget.setMaterial("Gold"); 
                                                widget.setAssemblyDescription("assembled with great care and skill"); widget.setPackageDescription("a fancy box with a ribbon");
												return widget; }
};

class GenericWidgetFactory : public WidgetFactory {
	public:
        Widget createWidget() override { Widget widget;
												widget.setPrice(10); widget.setName("Mass Produced Widget"); widget.setMaterial("Plastic"); 
                                                widget.setAssemblyDescription("assembled hastily and with poor QA"); widget.setPackageDescription("a plain brown box");
												return widget; }
};

int main() {
    FancyWidgetFactory fancyFactory;
    Widget fancyWidget = fancyFactory.createWidget();
	fancyWidget.description();

    GenericWidgetFactory genericFactory;
    Widget genericWidget = genericFactory.createWidget();
	genericWidget.description();

    return 0;
}
