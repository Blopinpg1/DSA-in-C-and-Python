def TOH(num, src, des, tmp):
    if num == 1:
        print(f"Move disk 1 from {src} to {des}\n")
        return

    TOH(num - 1, src, tmp, des)
    print(f"Move disk {num} from {src} to {des}\n")
    TOH(num - 1, tmp, des, src)


num = int(input("Enter the number of disks"))
TOH(num, "A", "C", "B")
