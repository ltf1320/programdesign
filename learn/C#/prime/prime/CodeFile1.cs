using System;
public partial class Employee
{
    private string _FirstName, _LastName;
    public string FirstName { get { return _FirstName; } set { OnFirstNameChange(value); _FirstName = value; } }
    public string LastName { get { return _LastName; } set { OnLastNameChange(value); _LastName = value; } }
    partial void OnLastNameChange(string value);
    partial void OnFirstNameChange(string value);
    public string Name
    {
        get
        {
            return FirstName + " " + LastName;
        }
        set
        {
            string[] names;
            names = value.Split(' ');
            if (names.Length == 2)
            {
                FirstName = names[0];
                LastName = names[1];
            }
            else
            {
                throw new ArgumentException(string.Format("Assign value '{0}' is invalid", value));
            }
        }
    }
}