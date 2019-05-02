import java.io.*;
import java.util.*;
import java.text.*;
public class File_Reader
{
    public static void main(String[] args)
    {
        final int SPOTS = 20;
        long lastChecked = 0;
        while(true)
        {

            try
            {
                long time = System.currentTimeMillis();

                SimpleDateFormat sdf = new SimpleDateFormat("MM-dd-yyyy");

                //System.out.println("After Format : " + sdf.format(time));


                File d = new File("/home/ubuntu/Research/" + sdf.format(time) + "/data.txt");// d - data file

                if (d.lastModified() > lastChecked)
                {
                    lastChecked = d.lastModified();

                    //System.out.print("Welcome to TruParking: \n");
                    FileReader dr = new FileReader(d); // dr - data file reader
                    BufferedReader db = new BufferedReader(dr);// db - data buffer reader
                    StringBuffer strbd = new StringBuffer(); // strbd - data sting buffer reader
                    String line;
                    String string = "";
                    int num = 0;

                    while ((line = db.readLine()) != null)
                    {
                        if (line.charAt(0) == 'E')
                        {
                            try
                            {
                                File s = new File ("/home/ubuntu/Research/spots.txt");// s - spots file
                                FileReader sr = new FileReader(s); // sr - spots file reader spotsReader
                                BufferedReader sb = new BufferedReader(sr); //sb - spots buffer reader spotsBuffer
                                StringBuffer strbs = new StringBuffer();// strbs - spots string buffer
                                //System.out.println("Entrance");
                                string = sb.readLine();
                                //num = Integer.parseInt(string);
                                //System.out.println(num);
                                num--;
                                PrintWriter sw = new PrintWriter(s, "UTF-8");
                                sw.println(SPOTS + num);
                                sw.close();

                            }
                            catch (IOException e)
                            {
                                System.err.println("Error: " + e);
                            }
                            catch (NumberFormatException e)
                            {
                                System.err.println("Invalid number");
                            }

                        }

                        else if (line.charAt(0) == 'X')
              			//System.out.println("Exit");

                            try
                            {
                                File s = new File ("/home/ubuntu/Research/spots.txt");// s - spots file
                                FileReader sr = new FileReader(s); // sr - spots file reader spotsReader
                                BufferedReader sb = new BufferedReader(sr); //sb - spots buffer reader spotsBuffer
                                StringBuffer strbs = new StringBuffer();// strbs - spots string buffer
                                //System.out.println("Exit");
                                string = sb.readLine();
                                //num = Integer.parseInt(string);
                                //System.out.println(num);
                                num++;
                                PrintWriter sw = new PrintWriter(s, "UTF-8");
                                sw.println(SPOTS + num);
                                sw.close();

                            }
                            catch (IOException e)
                            {
                                System.err.println("Error: " + e);
                            }
                            catch (NumberFormatException e)
                            {
                                System.err.println("Invalid number");
                            }
                        }
                        else
                        {
                            System.out.println("Unexpected Character...");
                        }
                        strbd.append(line);
                        strbd.append("\n");
                    }

                    dr.close();
                    //System.out.println("Contents of file:");
                    //System.out.println(strbd.toString());
                }
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
    }
}

