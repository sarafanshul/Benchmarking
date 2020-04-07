write-host N = 13
$curr_path = "E:\PRO\Benchmarking\N_Queens"
$allscripts = Get-ChildItem -Path $curr_path\* -Include "*.exe","*.class","*.py" | Select-Object -ExpandProperty FullName

foreach ($script in $allscripts) {
    
    If ($script -match 'exe') {
    	echo $script 
    	Measure-Command {$script}| Select-Object -Property TotalMilliseconds
    } ElseIf ($script -match 'class') {
    	echo $script
        $spt = $script.split("\"" "".", 100)
    	Measure-Command {java $spt[($spt.IndexOf("class")-1)]}| Select-Object -Property TotalMilliseconds
    } ElseIf ($script -match 'py') {
    	echo $script
    	Measure-Command {python $script}| Select-Object -Property TotalMilliseconds
    }
}