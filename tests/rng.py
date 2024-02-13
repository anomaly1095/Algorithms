"""Random list generators.

    
    Class
    -----
        random_number_generator
    
        Method
        -------------
               generate_unsorted_random_int_list
               generate_unsorted_random_float_list

"""

from random import randint, random



class InvalidInputError(Exception):
    pass


class unsorted_random_number_generator:
    
    @staticmethod
    def generate_unsorted_random_int_list(size: int, min: int, max: int)->any:
        """Generates unsorted integer list

        Args:
            size (int): size of list
            min (int) : minimum item value
            max (int): maximum item value
            
        Returns:
            List[int]: Populated list
        """
        
        if not isinstance(min, int) or not isinstance(max, int):
            raise InvalidInputError("min and max must be integers.")

        arr = [randint(min, max) for _ in range(size)]
        return arr
    
    @staticmethod
    def generate_unsorted_random_float_list(size: int)->any:
        """Generates unsorted float list

        Args:
            size (int): size of list

        Returns:
            List[float]: Populated list
        """
        arr = [random() for _ in range(size)]
        return arr
