using namespace System;
using namespace System::Configuration;

int main(array<System::String ^> ^args)
{
    DateTime dt = DateTime::Now;
    String^ NowStr = dt.ToShortDateString() + " " + dt.ToLongTimeString();

    String^ exePath = Reflection::Assembly::GetExecutingAssembly()->Location;
        
    System::Configuration::Configuration^ config =
        ConfigurationManager::OpenExeConfiguration(exePath);

    AppSettingsSection^ appSettingsSection = 
        (AppSettingsSection^)config->GetSection("appSettings");

    Console::WriteLine(appSettingsSection->SectionInformation->GetRawXml() + "\n");

    // Create a new app.config file or update LastRun setting
    if (appSettingsSection->Settings["LastRun"] == nullptr)
	{
        appSettingsSection->Settings->Add("LastRun", NowStr);
	}
    else
	{
        appSettingsSection->Settings["LastRun"]->Value = NowStr;
	}

    // Create a Toggle of a setting with a key and no value
    if (appSettingsSection->Settings["Toggle"] == nullptr)
	{
        appSettingsSection->Settings->Add("Toggle", nullptr);
	}
	else
    {
        appSettingsSection->Settings->Remove("Toggle"); 
    }

    // Clean up old run and add comma-delimited setting
    appSettingsSection->Settings->Remove("CommaDel");

    appSettingsSection->Settings->Add("CommaDel", "One");
    appSettingsSection->Settings->Add("CommaDel", "Two");
    appSettingsSection->Settings->Add("CommaDel", "Three");

    // Save an dump appSettings XML to Console
    config->Save();
    Console::WriteLine(appSettingsSection->SectionInformation->GetRawXml());

    // Create a Comma-delimited Converter
    CommaDelimitedStringCollectionConverter^ Converter = 
        gcnew CommaDelimitedStringCollectionConverter();

    // Convert setting to a CommaDelimitedStringCollection
    CommaDelimitedStringCollection^ collection = 
        (CommaDelimitedStringCollection^)Converter->ConvertFrom(
            appSettingsSection->Settings["CommaDel"]->Value);

    // Modify all comman-delimited values
    for (int i = 0; i < collection->Count; i++)
	{
        collection[i] = "**" + collection[i] + "**";
	}

    collection->Add("**Four**");
    collection->Remove("**Two**");

    // Restore collection back to setting value
    appSettingsSection->Settings["CommaDel"]->Value = collection->ToString();

    // Save an dump appSettings XML to Console
    config->Save();
    Console::WriteLine("\n" + appSettingsSection->SectionInformation->GetRawXml() + "\n\n\n\n");

    return 0;
}
