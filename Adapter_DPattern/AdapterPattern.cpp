#include<iostream>
#include<string>
using namespace std;



class IReportsTo {
public:
    virtual string getJSONData(const string data) = 0;
     virtual ~IReportsTo() {}
};

class XmlDataProvider {
public:
    string getXmlData(const string data) {
        size_t sep = data.find(':');
        string name = data.substr(0, sep);
        string id = data.substr(sep + 1);
        return "<user>"
            "<name>" + name + "</name>"
            "<id>" + id + "</id>"
            "</user>";
    }
};

// 3. Adapter: implements IReports by converting XML -> JSON
class XmlToJSONAdapter : public IReportsTo {
    XmlDataProvider* xmlDataProvider;
public:
    XmlToJSONAdapter(XmlDataProvider* xmlDataProvider) : xmlDataProvider(xmlDataProvider) {}
    string getJSONData(const string data) override {
        // get XML from the adapater
       string xml = xmlDataProvider->getXmlData(data);

       // 2. naively parse out <name> and <id> values
       size_t startName = xml.find("<name>") + 6;
       size_t endName = xml.find("</name>");
       size_t startId = xml.find("<id>") + 4;
       size_t endId = xml.find("</id>");

       string name = xml.substr(startName, endName - startName);
       string id = xml.substr(startId, endId - startId);

       return "{\"name\":\"" + name + "\", \"id\":\"" + id + "\"}";
    }
 
};

// 4. Client code works only with IReports

class Client {

public:

    string getReport(IReportsTo* reportsTo, const string data) {
        cout << "Processed JSON: "
      <<reportsTo->getJSONData(data)
      << endl;
    }
};


int main () {
     // 1. create the adaptee
    XmlDataProvider* xmlDataProvider = new XmlDataProvider();

    // 2. create the adapter
    XmlToJSONAdapter* adapter = new XmlToJSONAdapter(xmlDataProvider);
    
    // 3. give it some raw data
    string data = "Bob:1234";

    // 4. client print the json
    Client* client = new Client();
    client->getReport(adapter,data);
    // -> Processed Json : {"name":"Bob", "id":"1234"}

    // 5. clean up
    delete xmlDataProvider;
    delete adapter;
    delete client;

    return 0;
}




