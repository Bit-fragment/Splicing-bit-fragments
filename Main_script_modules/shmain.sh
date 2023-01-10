echo "pid:$$"
echo "参数个数:$#"
echo "脚本名字:$0"
echo "参数1:$1"
echo "参数2:$2"
#echo "所有参数列表:$@"

#funWithReturn() {
#  echo "这个函数会对输入的两个数字进行相加运算..."
#  echo "输入第一个数字: "
#  read aNum
#  echo "输入第二个数字: "
#  read anotherNum
#  echo "两个数字分别为 $aNum 和 $anotherNum !"
#  return $(($aNum + $anotherNum))
#}
#funWithReturn
#echo "输入的两个数字之和为 $? !"

function f1() {
  echo "第一个参数: $1 "
  echo "第二个参数: $2 "
  return $(($1 + $2))
}
f1 10 20
echo "执行f1()方法 $? "

Str="Hello Shell World"
length=${#Str}
echo "Length of '$Str' is $length"

#echo "Enter the your name: "
#read user_name
#echo "Your name is $user_name"
#echo
#echo "Enter your age, phone and email: "
#read age phone email
#echo "your age is:$age, phone is:$phone, email: $email "

#for i in {1..10}; do
#  sleep 0.05
#  echo "hello $((i))"
#done

#function f2() {
#  if [ $1 -le 1 ]; then
#    echo "-->1"
#    sleep 0.5
#    return 1
#  else
#    echo "-->2"
#    sleep 0.5
#    return $($(f2 $($1 - 1))+$1)
#  fi
#
#}
#f2 10
#echo "$?"

#echo "请输入"
#read n
#echo
#func() {
#  local i="$1"
#  if [ "$i" -le 1 ]; then
#    result=1
#  else
#    let "m=i-1"
#    func "$m"
#    let "result=$i + $?"
#  fi
#  return $result
#}
#func "$n"
#echo "$n的累加为：$?"
## $? 取函数的返回值时，这个数字的上限是很小的，只到255。

retValue=1         #全局变量 存储计算的值
function multi() { #递归实现累加
  local varNo1=$1
  local varNext=$(($varNo1 - 1))
  if [ $varNext -lt 1 ]; then
    retValue=1
  else
    multi $varNext
    retValue=$(expr $varNo1 + $retValue)
  fi
}
echo "开始递归时间: $(date)"
multi 100
echo "结束递归时间: $(date)"
echo $retValue


