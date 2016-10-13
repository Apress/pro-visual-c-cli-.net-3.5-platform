using namespace System;
using namespace System::Configuration;

#include "GameServerSection.h"
using namespace MyCustomSection;

int main(array<System::String ^> ^args)
{
    // Read GameServerSection 
    GameServerSection^ gameServer = 
        (GameServerSection^)ConfigurationManager::GetSection("GameServerSection");

    if (gameServer != nullptr) // false first time run
    {
        Console::WriteLine("Name = {0}   IP = {1}   Port = {2}\n\n", 
            gameServer->Name, 
            gameServer->IPAddress, 
            gameServer->Port);
    }

    // Create GameServer Section
    String^ exePath = Reflection::Assembly::GetExecutingAssembly()->Location;
        
    System::Configuration::Configuration^ config =
        ConfigurationManager::OpenExeConfiguration(exePath);

    GameServerSection^ gameServerSection = 
        (GameServerSection^)config->GetSection("GameServerSection");

    if (gameServerSection == nullptr)
    {
        gameServerSection = gcnew GameServerSection();
        config->Sections->Add("GameServerSection", gameServerSection);

        gameServerSection->Name = "Connector";
        gameServerSection->IPAddress = "192.168.1.101";
        gameServerSection->Port = 34501;
        
        config->Save();
    }

    Console::WriteLine(gameServerSection->SectionInformation->GetRawXml() + "\n");
}