<?php

function isPermutation($str1, $str2){
    if(strlen($str1) != strlen($str2)) return "false";
  
	for($i = 0; $i < strlen($str1); $i++){
       	if(!isset( $arr[$str1[$i]])) $arr[$str1[$i]] = 1; 
		else $arr[$str1[$i]]++;
		
		if(!isset( $arr2[$str2[$i]])) $arr2[$str2[$i]] = 1;   
		else $arr2[$str2[$i]]++;
	}
    
	 for($i = 0; $i < strlen($str1); $i++){
        if( !isset($arr[$str2[$i]]) ) return "false";
        if( !isset($arr2[$str1[$i]]) ) return "false";
    }
      
	return "true"; 
}

echo isPermutation("heelryo", "yeahlro");