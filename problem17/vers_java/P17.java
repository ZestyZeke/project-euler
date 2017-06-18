/*
 * P17.java
 *
 * Zeke Reyna
 *
 * Number letter counts:
 * If all the numbers from 1 to 1000 inclusive were written out in words,
 * how many letters would be used?
 */

import java.io.*;
public class P17
{
        static String[][] file_contents = new String[5][10];

        public static void process(String file_name)
        {
                BufferedReader rdr = null;
                String line_contents;
                int line, word;

                try {
                        rdr = new BufferedReader(new FileReader(new File(file_name)));

                        line = 0;
                        while ((line_contents = rdr.readLine()) != null) {

                                word = 0;
                                for (String num : line_contents.split(" ")) {

                                        file_contents[line][word] = num;
                                        word++;
                                }
                                line++;
                        }
                        rdr.close();

                } catch (IOException e) {
                        System.out.printf("error opening file\n");
                }
        }

        public static long count(int row, int col)
        {
                String num = file_contents[row][col];
                //System.out.printf("%s ", num);
                long letters = (long) num.length();
                return letters;
        }

        public static long find_num_letters(int num)
        {
                long num_letters = 0;

                int thousands_place = num / 1000;
                int hundreds_place  = num / 100 % 10;
                int tens_place      = num / 10 % 10;
                int ones_place      = num % 10;

                // thousands
                if (0 < thousands_place) {
                        num_letters += count(0, thousands_place);

                        // thousand
                        num_letters += count(3, 1);
                }

                // hundreds
                if (0 < hundreds_place) {
                        num_letters += count(0, hundreds_place);

                        // hundred
                        num_letters += count(3, 0);

                        // and
                        if ((tens_place + ones_place) > 0)
                                num_letters += count(4, 0);
                }

                // teens
                if (tens_place == 1)
                        num_letters += count(1, ones_place);

                // tens
                if (tens_place > 1)
                        num_letters += count(2, tens_place - 2);

                // ones
                if (0 < ones_place && tens_place != 1)
                        num_letters += count(0, ones_place);

                //System.out.printf("\n");
                return num_letters;
        }

        public static void main(String args[])
        {
                int num;
                int lower_bound, upper_bound;
                long sum_of_letters = 0;
                String file_name;

                if (args.length == 2) {
                        lower_bound = Integer.parseInt(args[0]);
                        upper_bound = Integer.parseInt(args[1]);
                } else {
                        lower_bound = 1; // defaults
                        upper_bound = 5;
                }

                file_name = "../num_words.txt";
                process(file_name);

                for (num = lower_bound; num <= upper_bound; num++)
                        sum_of_letters += find_num_letters(num);

                System.out.printf("\nThe sum of the letters from %d", lower_bound);
                System.out.printf(" to %d is: %d\n\n", upper_bound, sum_of_letters);
        }
}
