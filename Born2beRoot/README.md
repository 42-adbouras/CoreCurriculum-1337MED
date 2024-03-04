# ⚠️ The project is still in progress ⚠️

## Introduction

The aim of Born2beRoot is to learn and explore the fundamentals of `system administration` and `virtualization` by inviting us to install a `virtual machime` using VirtualBox.
We have to create a server respecting the partition scheme defined in the subject, and we have the right to choose between two Linux distributions (Debian or Rocky).
Here you can find the topics that we will examine, we are going to tackle the configuration of the server, I will not go through the installation.

# ToC

### [Mandatory](#i---mandatory)

- [Virtuallization](#virtuallization)
  * What is a Virtual Machine?
  * Advantages of a Virtual Machine
  * Types of virtuallization
- [LVM](#lvm)
  * What is LVM?
  * LVM components
  * What is encryption?
  * Purpose of sevaral partitions
- [Linux File System](#linux-file-system)
  * What is a File System?
  * Types of file systems
  * Directory Structure
  * What is Mounting?

- [SUDO](#sudo)
  * What is sudo?
  * Installing sudo
  * Configuring sudo
    
- [Packet Management in Debian](#packet-management-in-debian)
  * APT
  * Aptitude
  * The diffrence between APT & Aptitude

- [AppArmor](#apparmor)

- [UFW](#ufw)
  * What is UFW?
  * IP Addresses & Ports
  * Installing & Configuring UFW

- [SSH](#ssh)
  * What is SSH?
  * How does SSH works?
  * Installing & Configuring SSH
  * Port Forwarding in VirtualBox
 
- [Password Policy](#password-policy)

- [User And Group Management](#user-and-group-management)
  * Changing hostname
  * User Management
  * Group Management

- [Monitoring Script](#monitoring-script)
  * The script
  * The Wall Command
  * The Cron Service
 

### [Bonus](#ii---bonus)


# I - Mandatory
## Virtuallization
  * What is a Virtual Machine:\
    A virtual machine (VM) is a software emulation of a computer system. It operates based on the architecture and functions of a real or physical computer. VMs run applications and operating systems just like a physical computer. They allow multiple virtual machines to run on a single physical machine, sharing its resources such as CPU, memory, and storage. This enables efficient utilization of hardware and provides flexibility and isolation for running different operating systems and applications.
    
  * Advantages of a Virtual Machine:\
    `Resource Efficiency:` VMs allow multiple operating systems to run on a single physical machine, sharing resources efficiently.\
    `Isolation:` Each VM operates independently, which means that issues in one VM do not affect others.\
    `Flexibility:` VMs can be easily created, modified, or deleted without impacting the host system or other VMs.\
    `Testing and Development:` VMs provide a safe environment for testing new software or configurations without risking the host system.\
    `Disaster Recovery:` VMs can be backed up and restored quickly, which is crucial for business continuity and data recovery.\
    `Scalability:` VMs can be easily scaled up or down to meet changing demands.\
    `Cost Savings:` By consolidating multiple servers onto a single physical machine, VMs can reduce hardware costs.\
    `Portability:` VMs can be moved between different physical machines with minimal disruption.

  * Types of virtuallization:\
    There are two main types of virtualization:\
      `1. Hardware Virtualization:` Also known as Bare Metal, this involves creating a virtual version of an entire computer system, including the hardware. It allows multiple operating systems to run on a single physical machine, each with its own virtual hardware.\
      `2. Operating System Virtualization:` This involves running multiple isolated instances of an operating system on a single host, sharing the host's kernel but having separate user spaces. Containers are more lightweight than VMs and are often used for deploying applications.

    <p align="center">
    <img src="https://www.interviewbit.com/blog/wp-content/uploads/2022/05/Hypervisors-1024x955.png" style="width:500px">
    </p>

  * System Administration:\
    System administration is the practice of managing and maintaining computer systems, networks, and services. It involves a variety of tasks, including:\
    Installing and configuring hardware and software.\
    Managing user accounts and permissions.\
    Ensuring system security and compliance with policies.\
    Monitoring system performance and availability.\
    Troubleshooting and resolving technical issues.\
    Planning for system growth and capacity.\
    Keeping systems up-to-date with the latest patches and updates.\
    Sstem administrators are responsible for the smooth operation of IT infrastructure and are often the first point of contact for technical issues within an organization.
    
## LVM
  * What is LVM:\
    LVM, or Logical Volume Management, is a method of disk management that allows for the flexible allocation of disk space to logical volumes. Unlike traditional disk partitioning, which divides a physical disk into fixed-size partitions, LVM allows for the creation of logical volumes that can span multiple physical disks. This flexibility enables easier disk space management, including resizing, moving, and snapshotting of volumes.

  * LVM components:\
    Here's a brief overview of LVM components and concepts:\
`1. Physical Volumes (PVs):` These are the actual physical disks or partitions that are used by LVM. They are the lowest level of storage in LVM.\
`2. Volume Groups (VGs):` A volume group is a collection of one or more physical volumes that are combined to form a single logical unit. VGs are used to allocate disk space to logical volumes.\
`3. Logical Volumes (LVs):` These are the virtual partitions created within a volume group. They can be resized, moved, and snapshotted independently of the physical storage.\
`4. Physical Extents (PEs):` The smallest unit of disk space that can be allocated to a logical volume. A physical volume is divided into physical extents, which are then used to create logical volumes.\
`5. Snapshots:` LVM allows for the creation of snapshots of logical volumes. A snapshot is a point-in-time copy of a logical volume, which can be used for backup or testing purposes.\
`6. Striping:` LVM supports striping, which is the process of splitting data across multiple physical volumes to improve performance. This can be done at the volume level or within a single logical volume.\
`7. Mirroring:` LVM can also mirror data across multiple physical volumes to provide redundancy and improve data integrity.

    <p align="center">
    <img src="https://www.redhat.com/sysadmin/sites/default/files/styles/full/public/2020-03/LVM%20Cropped.jpg?itok=wz2G1Aci" style="width:600px">
    </p>

  * What is encryption:\
    Encryption is the process of converting plain, readable data into an unreadable format using algorithms and keys. This is done to secure the data and prevent unauthorized access, ensuring that only authorized parties with the corresponding decryption keys can access and understand the original information.\
    Based on the subject, when configuring volumes in Linux, particularly with Logical Volume Manager (LVM), the encryption is typically achieved using a software-based encryption mechanism called dm-crypt. dm-crypt is a kernel-level encryption module that provides transparent encryption of block devices, including logical volumes managed by LVM.

  * Purpose of sevaral partitions:\
    We could very well have a single partition to contain all of the operating system’s data, all of the software and all of the personal user files. The purpose of having several distinct partitions is to not put all our eggs in the same basket. If one file system becomes corrupted for example, only one of the partitions would be affected instead of the entire system.\
    In summary, the utilization of multiple partitions provides advantages such as organization, security, multi-boot capability, performance optimization, backup efficiency, and file system flexibility.
    
## Linux File System
  * What is a File System:\
    In Linux, a file system is a method of storing and organizing files on a storage device, such as a hard disk, solid-state drive, or network storage. It defines how data is stored, retrieved, and managed on the device. The file system is responsible for keeping track of files, directories, and the space on the disk. It provides a structure that allows users and applications to read from and write to files in a way that is efficient and organized.

  * Types of file systems:\
    Linux supports a variety of file systems, each with its own set of features and capabilities. Some of the most commonly used file systems in Linux includes:\
    `ext, ext2, ext3 and ext4:` The file system Ext stands for Extended File System. It was primarily developed for MINIX OS. The ext file system is an older version, and is no longer used due to some limitations.\
Ext2 is the first Linux file system that allows managing two terabytes of data. Ext3 is developed through Ext2; it is an upgraded version of Ext2 and contains backward compatibility. The major drawback of Ext3 is that it does not support servers because this file system does not support file recovery and disk snapshot.\
Ext4 file system is the faster file system among all the Ext file systems. It is a very compatible option for the SSD (solid-state drive) disks, and it is the default file system in Linux distribution.\
    `FAT32 and NTFS:` These are file systems commonly used in Windows environments but can also be used in Linux for compatibility with removable storage devices.\
    `JFS:` JFS stands for Journaled File System, and it is developed by IBM for AIX Unix. It is an alternative to the Ext file system. It can also be used in place of Ext4, where stability is needed with few resources. It is a handy file system when CPU power is limited.\
    `Swap:` The swap file system is used for memory paging in Linux operating system during the system hibernation. A system that never goes in hibernate state is required to have swap space equal to its RAM size.\
    `etc.:` There is much more to filesystems, if you want to dive deeper, [here](https://www.javatpoint.com/linux-file-system) is a good source.

    In summary, you can say that a filesystem serves as a signal or a "flag" to the operating system, indicating which driver to load for reading and writing data on a specific drive or partition.
    
  * Directory Structure:\
    The Linux directory structure is a hierarchical organization of files and directories that defines how data is stored and accessed on a Linux system. It's designed to make it easy for users and applications to find and access files. Here's a brief overview of the main directories in the Linux filesystem:\
    `/:` The root directory, is the top-level directory in the hierarchy. All other directories and files on the system are contained within this directory.\
    `/bin:` Contains essential command binaries that are needed for the system to boot and run. These are basic commands that are available to all users.\
    `/sbin:` Similar to /bin, but contains system binaries that are typically used for system maintenance and administration.\
    `/etc:` Contains system-wide configuration files. This directory is crucial for the configuration of the system and its services.\
    `/home:` Contains user directories. Each user has a directory under /home where their personal files and directories are stored.\
    `/usr:` Contains multi-user utilities and applications. This includes binaries, libraries, and documentation.\
    `/var:` Contains variable data files such as system logs, databases, and mail. This directory can grow in size over time.\
    `/tmp:` A temporary directory used for storing temporary files created by the system and users.\
    `/boot:` Contains files needed to boot the system, including the Linux kernel and initial RAM disk (initrd).\
    `/dev:` Contains device files that represent hardware devices. These files are used by the system to interact with hardware.\
    `/lib and /lib64:` Contain library files that are needed by the system and applications to run.\
    `/opt:` Used for optional or add-on software packages.\
    `/proc:` A virtual filesystem that provides information about the system and running processes.\
    `/sys:` Another virtual filesystem that provides a view into the kernel's view of the system's hardware.\
    `/mnt and /media:` Used for mounting external file systems.

  * What is Mounting:\
      Mounting in Linux is the process of making a file system available for use by attaching it to a specific directory in the existing file system hierarchy. This allows users and applications to access the files and directories on the mounted file system as if they were part of the main file system. The mount command is used to perform this operation, specifying the device and the mount point.

	## SUDO

* What is sudo?\
	sudo stands for "superuser do" is a command in Linux that allows a permitted user to execute a command as the superuser or another user, as specified by the security policy. The sudo command is used to perform administrative tasks that require elevated privileges, such as installing software, modifying system files, or changing system settings.
* Instaling sudo:\
  In order to install sudo, first we need to login as root.
	```
 	# su root
  	<enter the root password>
  	# apt update
  	# apt upgrade
  	# apt install sudo
	```
    Now, we need to give our regular user the ability to use sudo, by adding the user to the sudo group (and checking that it was added successfully).
    ```
    # sudo usermod -aG sudo <username>
    # getent group sudo
    ```
    To check if we now have sudo privileges, we can `exit` the root session to go back to our own user, then run the following command:
    ```
    # sudo whoami
    <enter password>
    root
    ```
    Once our password entered, we should get, as an answer, `root`. If that doesn’t work, we might have to logout and log back in for the changes to take effect.\
    As a very last resort, if the user still has no sudo privileges after logging out and back in again, we will have to modify the `sudoers.tmp` file from the root session 	with the following commands:
    ```
    # su
    # sudo visudo
    ```
    And add this line to the file:
    ```
    <username>   ALL=(ALL:ALL) ALL
    ```
* Configuring sudo:\
  For security reasons, the Born2beroot subject requires a few more sudo configurations. We must:
  	* Limit authentication for sudo to 3 tries for a bad password.
	* Define a custom message in case of a bad password.
	* Log sudo commands in `/var/log/sudo/`.
	* And activate TTY to stop malicious software from giving itself root privileges via sudo.
   
In order to do this, we need to add the following lines to the `sudoers.tmp` file (as above, we must open it from the `root` session, with the `sudo visudo` command to be able to write changes to it):

	Defaults     passwd_tries=3	// 3 attempts for bad password
	Defaults     secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"	// Paths that can be used by sudo
	Defaults     badpass_message="Wrong password. Try again!"
	Defaults     logfile="/var/log/sudo/sudo.log"
	Defaults     log_input
	Defaults     log_output
	Defaults     requiretty
 
If the `/var/log/sudo` directory doesn’t exist, we might have to `mkdir sudo` in `/var/log/`.\
Now, we can have root privileges in secure way, without having to log into the root session.
  
## Packet Management in Debian
   In Linux-based operating systems such as Debian, software installation is achieved through packages. These packages encapsulate all the necessary files required for executing a specific set of commands or functionalities. Thus, it's crucial to understand how to install these packages on our Born2beroot virtual machine.
   
  * APT:\
    APT (Advanced Package Tool) is a package management command-line tool used by Debian. It simplifies the process of managing software packages on Linux systems. apt provides a high-level command-line interface for the package management system and is designed to handle the installation, upgrade, and removal of software packages, as well as the management of package dependencies.\
    Here are some of the key functionalities provided by apt:\
`Installing Packages:` You can install new software packages using the `apt install` command.\
`Updating Package Lists:` Before installing new packages, it's a good practice to update the package lists to ensure you're getting the latest versions. This is done with the `apt update` command.\
`Upgrading Packages:` To upgrade all installed packages to their latest versions, you can use the `apt upgrade` command.\
`Removing Packages:` If you no longer need a package, you can remove it using the `apt remove` command.\
`Searching for Packages:` You can search for available packages using the `apt search` command.\
`Cleaning Up:` apt also allows you to clean up unnecessary packages and dependencies that were installed as dependencies but are no longer needed with the `apt autoremove` command.

  * Aptitude:\
    Aptitude also like APT, it's a high-level package management interface for Debian-based systems, it provides a text-based interface similar to a menu-driven package manager, making it more user-friendly for some users who prefer graphical interfaces.
Aptitude can perform most package management tasks, including installing, removing, and upgrading packages, as well as searching for packages and resolving package dependencies.
Aptitude also includes features like package filtering, package previewing, and a powerful dependency resolver.

  * The diffrence between APT & Aptitude:\
    `Interface:` APT primarily offers a command-line interface, whereas Aptitude provides a text-based menu-driven interface.\
`Functionality:` Both tools can perform similar package management tasks, but Aptitude may offer additional features like package filtering and previewing.\
`User Experience:` Aptitude may be preferred by users who are more comfortable with graphical or menu-driven interfaces, while APT may be preferred by those who prefer command-line interfaces.\
`Resource Usage:` Aptitude tends to use slightly more system resources compared to APT due to its interactive interface and additional features.\
In summary, both APT and Aptitude are powerful package management tools in Debian-based Linux distributions, each with its own set of features and interface preferences. Users can choose the tool that best fits their needs and workflow.

## AppArmor
   AppArmor is a Linux security module that restricts the capabilities of individual programs by enforcing security policies, ensuring that programs can only perform actions that are explicitly allowed. It come preinstalled in Debian.\
   AppArmor uses profiles to define the security policies for each program. A profile is a set of rules that specify what actions a program can perform and on which files or directories. Profiles are stored in the `/etc/apparmor.d/` directory.\
   Apparmor has two types of profile modes, `enforced` and `complain`. Profiles in enforcement mode enforce that profile's rules and report violation attempts in `/var/log/syslog`. Profiles in complain mode don't enforce any profile rules, just log violation attempts.
   The `apparmor-utils` package contains command line tools for configuring Apparmor. Using it you can change Apparmor's execution mode, find the status of a profile create new profiles, etc.
   
These are the most common commands:
   * You can check Apparmor's status with `aa-status`.
   * To put a profile in `complain` mode you can use `sudo aa-complain /path/to/profile`, `</path/to/profile>` path where the profile directory is located.
   * To put a profile in `enforced` mode you can use `sudo aa-enforce /path/to/profile`.
   * You can read more over [here](https://askubuntu.com/questions/236381/what-is-apparmor).

## UFW
* What is UFW:\
     UFW, or Uncomplicated Firewall, is a user-friendly front-end for managing iptables firewall rules in Linux. It simplifies the process of configuring a firewall, making it easier for users to set up and manage firewall rules without needing to understand the complexities of iptables directly. UFW is designed to be straightforward and easy to use, making it a popular choice for managing firewall settings on Linux systems.
* IP Addresses & Ports:\
	When we talk about traffic and networks, we must understand to things; IP addresses and ports.\
	An IP address is a unique identifier assigned to each device connected to a network, allowing it to communicate with other devices. It can be either IPv4 (Internet Protocol version 4) or IPv6 (Internet Protocol version 6), with IPv4 being the most commonly used format.\
	A port is a communication endpoint in a computer's networking stack. It allows a computer to distinguish between different types of traffic and to manage multiple connections to the same IP address. Ports are identified by numbers, with the range from 0 to 65535. Common port numbers include 80 for HTTP traffic, 443 for HTTPS, and 22 for SSH.
	Together, an IP address and a port number form a socket, which is used to identify a specific process or service on a device. This combination allows multiple services to run on the same device, each accessible via a unique combination of IP address and port number.
* Installing & Configuring UFW:\
  As the subject suggests the firewall must be active when you launch your virtual machine.
  ```
  $ sudo apt update
  $ sudo apt upgrade
  $ sudo apt install ufw
  $ sudo ufw enable
  ```
	To check if UFW up and running we can use the command line:
  ```
  $ sudo systemctl status ufw
  ```
  	We should see “active” in green.\
	Also we have to leave only port 4242 open.
  ```
  $ sudo ufw allow 4242
  ```
  To delete any uneseserry rules, you can list all available rules with the command line:
  ```
  $ sudo ufw status numbered
  ```
  And then delete them with the `delete` plus the rule's index:
  ```
  $ sudo ufw delete 2
  ```
     

## SSH
* What is SSH?\
    SSH (Secure Shell) is a cryptographic network protocol used for secure communication over an unsecured network. It provides a secure way to access and manage remote systems or devices over a network, such as the internet. SSH is commonly used for tasks like remote command execution, file transfer, and tunneling network connections.
* How does SSH works?\
    SSH commonly uses asymmetric encryption as part of its authentication process. Asymmetric encryption, also known as public-key cryptography, works with a pair of cryptographic keys: a `public key` and a `private key`.\
    The public key is used to encrypt data, while the private key is used to decrypt it. Messages encrypted with the public key can only be decrypted with the corresponding private key, ensuring secure communication without the need to share secret keys.
<p align="center">
<img src="https://www.hostinger.com/tutorials/wp-content/uploads/sites/2/2017/07/asymmetric-encryption.webp" style="width:600px">
</p>

* You can read more over [here](https://www.hostinger.com/tutorials/ssh-tutorial-how-does-ssh-work#How_Does_SSH_Work).

* Installing & Configuring SSH:\
    In Born2beroot, we are asked to install this protocol and route it trough the 4242 port. OpenSSH is the most popular and widespread tool, so let’s install that one. Since we want to be able to connect to our Born2beroot machine from another machine, we need the openssh-server packet. In order to connect to another machine from the Born2beroot machine, we would need the openssh-client packet.
  
```
$ sudo apt update
$ sudo apt upgrade
$ sudo apt install openssh-server
$ sudo systemctl enable ssh.service
```
To check SSH is up and running we can use the command line:
```
$ sudo systemctl status ssh.service
```
We should see “active” in green.\
Now we need to modify the ports that SSH is listening to, that can be done by editing the ssh configuration file:

```
$ sudo nano /etc/ssh/sshd_config
```

The line we are looking for is towards the beginning of the file and reads “#Port 22”. We want to `uncomment` that and change it to “Port 4242”
```
...
Include /etc/ssh/sshd_config.d/*.conf

Port 4242
#AddressFamily any
...
```
Also the jubject mentioned "For security reasons, it must not be possible to connect using SSH as root.", for that we can `uncomment` the rule `PermitRootLogin` and set it to `no`.
  	
```
...
# Authentication:

#LoginGraceTime 2m
PermitRootLogin no
#StrictModes yes
...
```
Then, we have to restart the ssh service for the change to take effect.
```
$ sudo systemctl restart ssh
```

If you want to generaye your public & private keys you can use the command `ssh-keygen`.\
Let’s not forget to tell our firewall to authorize the 4242 port connection! We might also have to delete a new rule about Port 22 which was added automatically with OpenSSH’s installation.
* Port Forwarding in VirtualBox:\
	Before we can connect to the virtual machine from another computer via SSH, we have to make a little adjustment in VirtualBox. Indeed, the connection will be refused until we forward the host port to the VM port.\
In VirtualBox, select the Born2beroot machine and go into configuration settings.
<p align="center">
<img src="https://cdn.discordapp.com/attachments/714092571655274496/1212377136321531945/Screen_Shot_2024-02-28_at_1.33.13_PM.png?ex=65f19d32&is=65df2832&hm=8737d65a1f71e8809b597414a0286ce8f0794812892677bc61d0b24fac0b569d&" style="width:600px">
</p>
	Then, go to network >> Adapter 1 >> Advanced >> Port Forwarding. Then we will redirect the host port 4242 to the guest port 4242 like this:
<p align="center">
<img src="https://cdn.discordapp.com/attachments/714092571655274496/1212378436837048351/Screen_Shot_2024-02-28_at_1.38.50_PM.png?ex=65f19e68&is=65df2968&hm=0995f9b64708c694ca910901a6ce79bcf261e751fb39e3c9c70b79e312bf3a45&" style="width:600px">
</p>
	Finally, on your virtual server, we are going to restart the SSH server once again and check its status:

```
$ sudo systemctl restart ssh
$ sudo systemctl status ssh	
```
* Logging into the Born2beroot Server via SSH:\
  Now that we have configured everything, we can check the SHH connection by attempting to log into the Born2beroot virtual machine from the host machine terminal. Of course, the virtual machine must be turned on to be able to connect to it.\
From the host machine’s terminal, we can connect via SSH with this command:
```
$ ssh <username_server>@<server_IP_address> -p <ssh_port>
```
The username will of course be that of the virtual machine user and the port will be 4242. But what is the IP address of our Born2beroot server? Since the virtual machine shares the host’s IP address, we can simply use the localhost IP address. Localhost is an internal shortcut that every computer uses to refer to their own IP address. The localhost IP is 127.0.0.1.\
So we can transcribe the previous command in one of the two following ways:
```
$ ssh mcombeau@localhost -p 4242
or
$ ssh mcombeau@127.0.0.1 -p 4242
<enter user passwor>
```
Once we enter the user password, we can control the virtual machine from the outside! Let’s note that the command prompt has changed and now shows the virtual machine’s hostname.\
In order to put an end to the SSH connection, all we need to do is:
```
exit
```

## Password Policy
* The subject consist of having a strong password policy, we have to implement the following reguirement:
	* Your password has to expire every 30 days.
	* The minimum number of days allowed before the modification of a password will
be set to 2.
	* The user has to receive a warning message 7 days before their password expires.
	* Your password must be at least 10 characters long. It must contain an uppercase
letter, a lowercase letter, and a number. Also, it must not contain more than 3
consecutive identical characters.
	* The password must not include the name of the user.
	* The following rule does not apply to the root password: The password must have
at least 7 characters that are not part of the former password.\
In order to configure the first 3 rules, we have to edit the `/etc/login.defs` file:
```
sudo nano /etc/login.defs
```
And find the “Password aging controls” section to change the values such that:
```
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```

However, these changes will not automatically apply to preexisting users. For both root and our first user, we need to use the `chage` command to enforce these rules. The `-l` flag is available to display which rules apply to a certain user.

```
$ sudo chage -M 30 <username/root>
$ sudo chage -m 2 <username/root>
$ sudo chage -W 7 <username/root>
$ sudo chage -l <username/root>
```
For the rest of the rules, we will have to install the password quality verification library.

```
$ sudo apt install libpam-pwquality
```

Then, we must edit the `/etc/security/pwquality.conf` configuration file. Here, we will need to remove the comment sign (#) and change the values of the various options. We will end up with something like this:

```
# Number of characters in the new password that must not be present in the 
# old password.
difok = 7
# The minimum acceptable size for the new password (plus one if 
# credits are not disabled which is the default)
minlen = 10
# The maximum credit for having digits in the new password. If less than 0 
# it is the minimun number of digits in the new password.
dcredit = -1
# The maximum credit for having uppercase characters in the new password. 
# If less than 0 it is the minimun number of uppercase characters in the new 
# password.
ucredit = -1
# ...
# The maximum number of allowed consecutive same characters in the new password.
# The check is disabled if the value is 0.
maxrepeat = 3
# ...
# Whether to check it it contains the user name in some form.
# The check is disabled if the value is 0.
usercheck = 1
# ...
# Prompt user at most N times before returning with error. The default is 1.
retry = 3
# Enforces pwquality checks on the root user password.
# Enabled if the option is present.
enforce_for_root
# ...
```
And that’s all there is to it!

## User And Group Management
* Changing hostname:\
  We can change the hostname with the following command:
```
$ sudo hostnamectl set-hostname <new_hostname>
```
We could also change the hostname by editing the files `/etc/hostname` & `/etc/hosts` instead.\
You need to restart the machime for changes to take effect.
* User management:\
  For the evaluation, we must be able to show a list of all users, add or delete user accounts, change their usernames, add or remove them from groups, etc. The following commands are necessary to do all of that:\
	`useradd <username>` : creates a new user.\
	`usermod <username>` : changes the user’s parameters: `-l` for the username, `-c` for the full name, `-g` for groups by group ID.\
	`userdel -r <username>` : deletes a user and all associated files.\
	`id -u <username>` : displays user ID.\
	`users` : shows a list of all currently logged in users.\
	`cat /etc/passwd | cut -d ":" -f 1` : displays a list of all users on the machine.\
	`cat /etc/passwd | awk -F ":" '{print $1}'` : same as above.

* Group Management:\
	In the same way, we will have to manage user groups. Our default personal user must be in the `sudo` and `user42` groups. The following commands need to be mastered for the evaluation:\
`groupadd` : creates a new group.\
`gpasswd -a` : adds a user to a group.\
`gpasswd -d` : removes a user from a group.\
`groupdel` : deletes a group.\
`groups` : displays the groups of a user.\
`id -g` : shows a user’s main group ID.\
`getent group` : displays a list of all users in a group.

## Monitoring Script
* The script:\
  The last thing we have to do for mandatory part is a bash script named `monitoring.sh`, it must display the following information every 10 minutes broadcasted on evey terminal connected to our virtual machine:
	* The architecture of your operating system and its kernel version:
   	```
    # uname --all
    ```
    * The number of physical processors.
	```
 	# lscpu | grep 'Socket(s)' | awk '{print $2}'
	```
	* The number of virtual processors.
	```
 	# lscpu | grep 'Core(s)' | awk '{print $4}'
	```
	* The current available RAM on your server and its utilization rate as a percentage.
	```
 	# free --mega | grep 'Mem' | awk '{print $3"/"$2"MB"}'
 	# free --mega | grep 'Mem' | awk '{printf "%.2f%%\n", $3 / $2 * 100}'
	```
 	* The current available memory on your server and its utilization rate as a percentage.
    ```
    # df -h --total | grep 'total' | awk '{print $3 "/" $2}'
    # df -h --total | grep 'total' | awk '{printf "%.2f%%\n", $3 / $2 * 100}'
    ```
	* The date and time of the last reboot.
	```
 	# who -b | awk '{print $3 " " $4}'
	```
	* Whether LVM is active or not.
   	```
    # if [ $(lsblk | grep 'lvm' | wc -l) == 0 ]; then echo "No"; else echo "Yes"; fi
    ```
	* The number of active connections.
   	```
    # ss -s | grep 'TCP:' | awk '{print $4 " ESTABLISHED"}' | tr -d ","
    ```
	* The number of users using the server.
   	```
    # who | awk '{print $1}' | sort -u | wc -l
    ```
	* The IPv4 address of your server and its MAC (Media Access Control) address. • The number of commands executed with the sudo program.
   	```
    # echo "IP " && hostname -I && ip link | grep 'link/ether' | awk '{printf "(%s)", $2}'
    ```
    * The number of commands executed with the sudo program.
  ```
  # grep 'COMMAND' /var/log/sudo/sudo.log | wc -l && echo "cmd"
  ```
NOTE ⚠️ : Some of the above command won't work without root permission, we need to login as root and create the monitoring.sh file on thier session.
We must also grant the file execution righ:
```
# chmod 755 monitoring.sh
```
The command `mpstat` is defined on `sysstat` package.
```
# apt install sysstat
```

* The Wall Command:\
  The wall command in Linux is used to broadcast a message to all users currently logged into the system. It sends a message to all terminals, including those that are idle or inactive. This can be useful for system administrators to communicate important information or announcements to all users at once.\
  Example:
  ```
  # echo "System will be rebooted in 10 minutes. Please save your work." | wall
  or
  # wall "System will be rebooted in 10 minutes. Please save your work."
  ```
* The Cron Service:\
  Cron is a program that enables the execution of scripts or software in an automatic way, at a certain date and time or at a specified interval. It is installed by default in Debian (we can check this with the `apt list cron` command). To be certain it will run at system startup, we should enable it:
  ```
  # systemctl enable cron
  ```
  Cron uses crontab files to schedule jobs. Each user can have one, or many. As the root user, we will now create one with the following command:
  ```
  # crontab -e
  ```
  The syntax of a cron file might seem obscure, but it’s not too hard to wrap your head around:
  ```
  * * * * * <command to execute>
  ```
  here is what each star represents:
  	```
  	.------------------------ minutes (0-59)
	| .-------------------- hours (0-23)
	| | .---------------- day of the month (1-31)
	| | | .------------ month of the year (1-12)
	| | | | .-------- day of the week (0-6, 0 = sunday)
	| | | | |
	* * * * * <command to execute>
  	```
   By replacing the stars with numerical values, we can define when our command must be executed.\
So is this the way we should write “every 10 minutes”?
  	```
   	10 * * * * bash /root/monitoring.sh
   	```
   Almost, but no. This instruction means “execute this at the tenth minute of each hour, every day of every month”. So our monitoring script won’t execute every 10 minutes, but only at midnight 10, 1:10, 2:10, 3:10, 4:10 and so on.\
  So how are we supposed to say “every 10 minutes”, then? Well, we can simply “divide” the minute star by 10.
  ```
  */10 * * * * bash /root/monitoring.sh
  ```
  If the wall command wasn’t incorporated directly into the monitoring.sh script, we can pipe it into this cron rule, like so:
  ```
  */10 * * * * bash /root/monitoring.sh | wall
  ```
  
# II - Bonus

* WordPress setup
  * What is WordPress:\
    WordPress is a free and open-source content management system (CMS) primarily used for creating websites, blogs, and online stores. It's one of the most popular website-building platforms globally, powering millions of websites on the internet.\
    WordPress provides a user-friendly interface, allowing individuals and businesses to create and manage their websites without needing advanced knowledge in a scripting language. It offers a wide range of themes and plugins, which extend its functionality and customization options.

    To setup a WordPress website we need three essential requiSITES, 'see what i did there, nevermind back to the subject!', a scripting language (PHP), a webserver manager (Lighttpd) and a database manager (MariaDB):

    `PHP:` Or Hypertext Preprocessor, is a very popular open-source programming language for the creation of dynamic web pages via web server. It is essential for the correct operation of WordPress.\
    `Lighttpd:` Or Lighty, is an open-source web server software designed for speed, efficiency, and scalability. Its primary job is to serve web content to clients, such as web browsers, efficiently and reliably. It can handle incoming HTTP requests from clients and delivering the appropriate web content in response.\
    `MariaDB:` MariaDB is a popular open-source relational database management system that is widely used for storing and managing data in various applications and websites. Its primary job is to provide a reliable, scalable, and efficient platform for storing, organizing, and retrieving structured data. MariaDB stores data in a structured format within tables, which consist of rows and columns. It supports various data types such as integers, strings, dates, and more.

    * WordPress Installation:
      To install PHP one packet is not enough


  




