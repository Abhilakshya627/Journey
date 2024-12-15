document.addEventListener('DOMContentLoaded', () => {
    // Smooth scrolling for navigation links
    const navLinks = document.querySelectorAll('nav a');
    navLinks.forEach(link => {
        link.addEventListener('click', (e) => {
            e.preventDefault();
            const targetId = e.target.getAttribute('href').substring(1);
            const targetSection = document.getElementById(targetId);
            window.scrollTo({
                top: targetSection.offsetTop,
                behavior: 'smooth'
            });
        });
    });

    // Toggle dark mode
    const toggleDarkMode = document.createElement('button');
    toggleDarkMode.textContent = 'Toggle Dark Mode';
    toggleDarkMode.style.position = 'fixed';
    toggleDarkMode.style.bottom = '20px';
    toggleDarkMode.style.right = '20px';
    toggleDarkMode.style.padding = '10px 20px';
    toggleDarkMode.style.backgroundColor = '#0078d7';
    toggleDarkMode.style.color = 'white';
    toggleDarkMode.style.border = 'none';
    toggleDarkMode.style.borderRadius = '5px';
    toggleDarkMode.style.cursor = 'pointer';
    document.body.appendChild(toggleDarkMode);

    // Check for saved user preference for dark mode
    if (localStorage.getItem('darkMode') === 'true') {
        document.body.classList.add('dark-mode');
    }

    toggleDarkMode.addEventListener('click', () => {
        document.body.classList.toggle('dark-mode');
        localStorage.setItem('darkMode', document.body.classList.contains('dark-mode'));
    });

    // Dark mode styles
    const darkModeStyles = document.createElement('style');
    darkModeStyles.textContent = `
        .dark-mode {
            background-color: #333;
            color: #f4f4f4;
        }
        .dark-mode header {
            background: linear-gradient(to right, #004d99, #00264d);
        }
        .dark-mode nav {
            background: #444;
        }
        .dark-mode nav a {
            color: #f4f4f4;
        }
        .dark-mode nav a:hover {
            background-color: #00264d;
        }
        .dark-mode section {
            background: #444;
        }
        .dark-mode footer {
            background: #222;
        }
    `;
    document.head.appendChild(darkModeStyles);

    // Handle contact form submission (placeholder)
    const contactForm = document.getElementById('contact-form');
    contactForm.addEventListener('submit', (e) => {
        e.preventDefault();
        // Here you would typically handle the form submission, e.g., send data to a server
        alert('Thank you for your message! I will get back to you soon.');
        contactForm.reset(); // Reset the form after submission
    });
});