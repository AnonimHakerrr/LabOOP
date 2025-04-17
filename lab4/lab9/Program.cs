using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace lab9
{
    public class Adressa
    {
        string _country, _city, _street, _zipCode;
        public Adressa(string country, string city, string street, string zipCode)
        {
            _country = country;
            _city = city;
            _street = street;
            _zipCode = zipCode;
        }
        public Func<string, string> ValidationString = value =>
        {
            if (string.IsNullOrEmpty(value))
                throw new ArgumentNullException("Value cannot be null or empty.");
            return value;
        };
        public string Country
        {
            get => _country;
            set => _country = ValidationString(value);
        }
        public string City
        {
            get => _city;
            set => _city = ValidationString(value);
        }
        public string Street
        {
            get => _street;
            set => _street = ValidationString(value);
        }
        public string ZipCode
        {
            get => _zipCode;
            set
            {
                if (Regex.IsMatch(value, @"^\d{5}$"))
                    _zipCode = value;
                else
                    throw new ArgumentException("Invalid zip code format. It should be 5 digits long.");
            }
        }

    }

    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Adressa address = new Adressa("USA", "New York", "5th Avenue", "10001");
                Console.WriteLine($"Country: {address.Country}");

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            System.Threading.Thread.Sleep(10000);
        }
    }
}
