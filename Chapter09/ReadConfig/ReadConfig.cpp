using namespace System;
using namespace System::Configuration;

int main(array<System::String ^> ^args)
{
    for each (String^ key in ConfigurationManager::AppSettings->AllKeys)
    {
        Console::WriteLine("Key = {0}  \tValue = {1}", 
            key, 
            ConfigurationManager::AppSettings[key]);
    }

    AppSettingsReader^ reader = gcnew AppSettingsReader();
    
    String^ myString = (String^)reader->GetValue("A_String", String::typeid);
    double myNumber = (double)reader->GetValue("A_Number", double::typeid);
    DateTime myDateTime = (DateTime)reader->GetValue("A_DateTime", DateTime::typeid);

    Console::WriteLine("\nString^ [{0}] float [{1}] DateTime [{2} {3}]\n",
        myString,
        myNumber,
        myDateTime.ToShortDateString(),
        myDateTime.ToLongTimeString());

	String^ exePath = Reflection::Assembly::GetExecutingAssembly()->Location;
		
    System::Configuration::Configuration^ config =
        ConfigurationManager::OpenExeConfiguration(exePath);

    AppSettingsSection^ appSettingsSection = 
        (AppSettingsSection^)config->GetSection("appSettings");

	for each (String^ key in appSettingsSection->Settings->AllKeys)
	{
        Console::WriteLine("Key = {0}  \tValue = {1}", 
            key, 
            appSettingsSection->Settings[key]->Value);
	}

    Console::WriteLine("\n" + appSettingsSection->SectionInformation->GetRawXml());

    return 0;
}
