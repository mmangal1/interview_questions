import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

//sorts a string in order of frequency and then alphabetically 
public class stringFormater {

	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String input = scan.nextLine();
		char[] inputCharArray = input.toCharArray();

		HashMap<Character, Integer> charFreqCountMap = new HashMap<>();
		
		//Count frequency
		for(int x = 0; x < inputCharArray.length; x++){
			if(charFreqCountMap.containsKey(inputCharArray[x])){
				int val = charFreqCountMap.get(inputCharArray[x]);
				charFreqCountMap.put(inputCharArray[x], ++val);
			}else{
				charFreqCountMap.put(inputCharArray[x], 1);
			}
		}

		//Sort based on frequency	
		TreeMap<Integer, TreeSet<Character>> sortedFreqSet = new TreeMap<>();
		for(int x = 0; x < inputCharArray.length; x++){
			
			//if listed frequency is already in the map, then add the new character in the set as well
			if(sortedFreqSet.containsKey(charFreqCountMap.get(inputCharArray[x]))){
				sortedFreqSet.get(charFreqCountMap.get(inputCharArray[x])).add(inputCharArray[x]);
			}else{
				TreeSet<Character> inputCharSet = new TreeSet<>();
				inputCharSet.add(inputCharArray[x]);
				sortedFreqSet.put(charFreqCountMap.get(inputCharArray[x]), inputCharSet);
			}
		}
		
		Map<Integer, TreeSet<Character>> alphaFreqSet = sortedFreqSet.descendingMap();
		String result = "";
		for(int x : alphaFreqSet.keySet()){
			TreeSet<Character> set = alphaFreqSet.get(x);
			for(char c : set){
				for(int i = 0; i < x; i++)
					result += c;
			}
		}
		
		System.out.println(result);
		
	}
}