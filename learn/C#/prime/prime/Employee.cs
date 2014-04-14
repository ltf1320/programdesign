using System;
partial class Employee
{
    partial void OnLastNameChange(string value)
    {
        if (value == null)
        {
            throw new ArgumentNullException("LastName");
        }
        if (value.Trim().Length == 0)
        {
            throw new ArgumentException("Last Name cannot be empty.");
        }
    }
    partial void OnFirstNameChange(string value)
    {
        return;
    }
}