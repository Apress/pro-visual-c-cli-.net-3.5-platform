namespace MyCustomSection
{
    ref class GameServerSection : public ConfigurationSection
    {
    public:
        GameServerSection() { }

       [ConfigurationPropertyAttribute("Port",IsRequired=true)]
        property int Port
        {
            int get() { return (int)this["Port"]; }
            void set(int value) { this["Port"] = value; }
        }

      [ConfigurationPropertyAttribute("IPAddress",IsRequired=true)]
       property String^ IPAddress
        {
            String^ get() { return (String^)this["IPAddress"]; }
            void set(String^ value) { this["IPAddress"] = value; }
        }

      [ConfigurationPropertyAttribute("Name",IsRequired=true)]
       property String^ Name
        {
            String^ get() { return (String^)this["Name"]; }
            void set(String^ value) { this["Name"] = value; }
        }
    };
}
